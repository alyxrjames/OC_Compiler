%{
// $Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYPRINT yyprint
#define YYMALLOC yycalloc

static void* yycalloc (size_t size);

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%destructor { error_destructor ($$); } <>

%token  ROOT TOK_IDENT NUMBER
%token  TOK_VOID TOK_BOOL TOK_CHAR
%token  TOK_INT TOK_STRING TOK_RETURN
%token  TOK_IF TOK_ELSE TOK_WHILE 
%token  TOK_FALSE TOK_TRUE TOK_NULL
%token  TOK_EQ TOK_LT TOK_GT 
%token  TOK_GE TOK_LE TOK_NE
%token  TOK_INTCON TOK_CHARCON TOK_STRINGCON
%token  TOK_STRUCT TOK_ORD TOK_CHR
%token  TOK_ARRAY TOK_NEW

%token  TOK_ROOT TOK_FIELD TOK_DECLID 
%token  TOK_TYPEID TOK_INDEX 
%token  TOK_POS TOK_NEG
%token  TOK_CALL TOK_NEWARRAY TOK_NEWSTRING
%token  TOK_IFELSE TOK_RETURNVOID TOK_BLOCK
%token  TOK_VARDECL TOK_FUNCTION TOK_PARAMLIST
%token  TOK_PROTOTYPE 

%right  TOK_IF TOK_ELSE
%right  '='
%left   TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left   '+' '-' 
%left   '*' '/' '%'
%right  '!' TOK_POS TOK_NEG TOK_NEW 
%left   '[' '.' TOK_CALL   
%nonassoc '('

%start  program


%%

program : program structde             			{ $$ = adopt1($1,$2); }
	| program func					{ $$ = adopt1($1,$2); }
        | program stmt                    		{ $$ = adopt1($1,$2); }	
	|						{ $$ = new_parseroot(); } 
        ;

structde: TOK_STRUCT TOK_IDENT '{' '}'			{change_sym($2,TOK_TYPEID); $$ = adopt1($1,$2);free_ast2($3,$4);}
	| TOK_STRUCT TOK_IDENT s_stmts '}'		{change_sym($2,TOK_TYPEID); $$ = adopt2($1,$2,$3);free_ast($4);}
	;

s_stmts	: '{' fielddec ';'				{ $$ = adopt1($1,$2);free_ast($3);}
	| s_stmts fielddec ';'				{ $$ = adopt1($1,$2);free_ast($3);}
	;

fielddec: basetype TOK_IDENT				{change_sym($2,TOK_FIELD); $$ = adopt1($1,$2);}
	| basetype TOK_ARRAY TOK_IDENT			{change_sym($3,TOK_FIELD); $$ = adopt2($2,$1,$3);}
	;

basetype: TOK_VOID					{ $$ = $1;}
       	| TOK_INT					{ $$ = $1;}
	| TOK_STRING					{ $$ = $1;}
	| TOK_TYPEID					{ $$ = $1;}	
	;

func	: identdec '(' ')' block			{ $$ = adopt3(new_astree(TOK_FUNCTION,$1->filenr,$1->linenr,$1->offset,""),$1,$2,$4);free_ast($3);}
     	| identdec '(' ')' ';'				{ $$ = adopt2(new_astree(TOK_PROTOTYPE,$1->filenr,$1->linenr,$1->offset,""),$1,$2);free_ast2($3,$4);}
	| identdec paramli ')' ';'			{ $$ = adopt2(new_astree(TOK_PROTOTYPE,$1->filenr,$1->linenr,$1->offset,""),$1,$2);free_ast2($3,$4);}
     	| identdec paramli ')' block			{ $$ = adopt3(new_astree(TOK_FUNCTION,$1->filenr,$1->linenr,$1->offset,""),$1,$2,$4);free_ast($3);}
	;

paramli	: paramli ',' identdec				{ $$ = adopt1($1,$3);free_ast($2);} 
	| '(' identdec				{ $$ = adopt1sym($1,$2,TOK_PARAMLIST);}
	;

identdec : basetype TOK_IDENT				{change_sym($2,TOK_DECLID);$$ = adopt1($1,$2);}
	  | basetype TOK_ARRAY TOK_IDENT		{change_sym($3,TOK_DECLID);$$ = adopt2($2,$1,$3);}	
	  ;

block	: ';'						{$$ = $1;}	
      	| '{' '}'					{change_sym($1,TOK_BLOCK);$$ = $1;free_ast($2);}
      	| b_stmts '}'					{$$ = $1; free_ast($2);}
	;

b_stmts	: '{' stmt					{$$ = adopt1sym($1,$2,TOK_BLOCK);}
	| b_stmts stmt					{$$ = adopt1($1,$2);}
	;

stmt	: block						{$$ = $1;}
    	| vardecl					{$$ = $1;}
	| while						{$$ = $1;}
	| ifelse					{$$ = $1;}
	| return					{$$ = $1;}
	| expr ';'					{$$ = $1;free_ast($2);} 
     	;

vardecl	: identdec '=' expr ';'				{ $$ = adopt1(adopt1sym($2,$1,TOK_VARDECL),$3);free_ast($4);}
	;

while	: TOK_WHILE '(' expr ')' stmt			{$$ = adopt2($1, $3, $5);free_ast2($2,$4);}
      	;

ifelse	: TOK_IF '(' expr ')' stmt			{ $$ = adopt2 ($1,$3,$5);free_ast2($2,$4);} 
       	| TOK_IF '(' expr ')' stmt TOK_ELSE stmt	{ $$ = adopt2(adopt1sym($1,$3,TOK_IFELSE),$5,$7);free_ast2($2,$4);free_ast($6);}
	;

return	: TOK_RETURN expr ';'				{ $$ = adopt1 ($1, $2);free_ast($3);}
       	| TOK_RETURN ';'				{ change_sym($1,TOK_RETURNVOID);$$ = $1;free_ast($2);}
       	;

expr    : TOK_CHR expr					{ $$ = adopt1 ($1, $2);} 
	| TOK_ORD expr					{ $$ = adopt1 ($1, $2);}
       	| expr TOK_EQ expr				{ $$ = adopt2 ($2, $1, $3); } 
	| expr TOK_NE expr				{ $$ = adopt2 ($2, $1, $3); }
	| expr TOK_LT expr				{ $$ = adopt2 ($2, $1, $3); }
	| expr TOK_GT expr				{ $$ = adopt2 ($2, $1, $3); }
	| expr TOK_LE expr				{ $$ = adopt2 ($2, $1, $3); }
	| expr TOK_GE expr				{ $$ = adopt2 ($2, $1, $3); }
	| '!' expr					{ $$ = adopt1 ($1, $2); } 
	| expr '=' expr         			{ $$ = adopt2 ($2, $1, $3); }
        | expr '+' expr        				{ $$ = adopt2 ($2, $1, $3); }
        | expr '-' expr         			{ $$ = adopt2 ($2, $1, $3); }
        | expr '*' expr         			{ $$ = adopt2 ($2, $1, $3); }
        | expr '/' expr         			{ $$ = adopt2 ($2, $1, $3); }
        | '+' expr %prec POS    			{ $$ = adopt1sym ($1, $2, POS); }
        | '-' expr %prec NEG    			{ $$ = adopt1sym ($1, $2, NEG); }
        | '(' expr ')'          			{ free_ast2 ($1, $3); $$ = $2; }
        | TOK_IDENT                 			{ $$ = $1; }
        | NUMBER                			{ $$ = $1; }
	| allocator					{ $$ = $1; }
	| call						{ $$ = $1; }
	| variable					{ $$ = $1; }
	| constant					{ $$ = $1; } 
        ;


allocator	: TOK_NEW TOK_IDENT '(' ')'		{change_sym($2,TOK_TYPEID);$$ = adopt1($1,$2);free_ast2($3,$4);}
	  	| TOK_NEW TOK_STRING '(' expr ')' 	{$$ = adopt1sym($1,$4,TOK_NEWSTRING);free_ast($2);free_ast2($3,$5);}
		| TOK_NEW basetype '[' expr ']'		{$$ = adopt1(adopt1sym($1,$2,TOK_NEWARRAY),$4); free_ast($3);free_ast($5); }
		;
call		: TOK_IDENT '(' ')'			{$$ = adopt1(adopt1sym($2,$1,TOK_CALL),$3);}
		| c_args ')'				{$$ = $1; free_ast($2);}
		;
c_args		: TOK_IDENT '(' expr 			{$$ = adopt1(adopt1sym($2,$1,TOK_CALL),$3);}
		| c_args ',' expr			{$$ = adopt1($1,$3); free_ast($2);} 
		;

variable	: TOK_IDENT				{$$ = $1;}
	 	| expr '[' expr ']'			{$$ = adopt1(adopt1sym($2,$1,TOK_INDEX),$3);
							free_ast($4);}
		| expr '.' TOK_FIELD			{change_sym($2,TOK_FIELD);$$ = adopt2($2,$1,$3);}
		;
constant	: TOK_INTCON				{$$ = $1;}
	 	| TOK_CHARCON				{$$ = $1;}
		| TOK_STRINGCON 			{$$ = $1;}
		| TOK_NULL				{$$ = $1;}
		;
%%

const char* get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}

RCSC("$Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $")

