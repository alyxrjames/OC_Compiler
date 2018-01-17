%{
#include <cassert>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"
%}

%debug
%defines
%error-verbose
%token-table
%verbose


%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token TOK_ORD TOK_CHR TOK_ROOT
%token TOK_DECLID TOK_INDEX TOK_NEWSTRING
%token TOK_RETURNVOID TOK_VARDECL TOK_FUNCTION
%token TOK_PARAMLIST TOK_PROTOTYPE

%right TOK_IF TOK_ELSE
%right '='
%left  TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left  '+' '-'
%left  '*' '/' '%'
%right '!' TOK_NEW TOK_ORD TOK_CHR TOK_POS TOK_NEG
%left  '[' '.' TOK_CALL
%nonassoc '('



%start program

%%



program : program structdef {$$ = adopt1($1,$2);}
	| program function  {$$ = adopt1($1,$2);}
	| program statement  {$$ = adopt1($1,$2);}
	| program error '}' {$$ = $1;}
	| program error ';' {$$ = $1;}
	|		    {$$ = new_parseroot();}
	;



structdef: declarations '}' {$$ = $1; free_ast($2);}
	;

fielddecl: basetype TOK_IDENT 			{change_sym($2, TOK_FIELD); $$ = adopt1($1,$2);}
	|  basetype TOK_ARRAY TOK_IDENT		{change_sym($3, TOK_FIELD); $$ = adopt2($2,$1,$3);}
	;


declarations: TOK_STRUCT TOK_IDENT '{'		{change_sym($2,TOK_TYPEID); $$ = adopt1($1,$2);
						free_ast($3);}
	| declarations fielddecl ';'		{$$ = adopt1($1,$2); free_ast($3);}
	;


basetype: TOK_VOID 	{$$ = $1;}
	| TOK_BOOL 	{$$ = $1;}
	| TOK_CHAR 	{$$ = $1;}
	| TOK_INT 	{$$ = $1;}
	| TOK_STRING 	{$$ = $1;}
	| TOK_IDENT	{$$ = change_sym($1, TOK_TYPEID);}
	;

function: identdecl '(' ')' ';'	 	 
					 {$$ = adopt2(new astree(TOK_PROTOTYPE,
					 $1 -> filenr, $1 -> linenr, $1 -> offset, ""),$1,$2);
				 	 free_ast2($3,$4);}

	| identdecl '(' ')' block	 {$$ = adopt3(new astree(TOK_FUNCTION, $1 -> filenr,
					 $1 -> linenr, $1 -> offset, ""), $1, $2, $4); 
					 free_ast($3);}

	| identdecl funcp ')' block	 {$$ = adopt3(new astree(TOK_FUNCTION, $1 -> filenr,
					 $1 -> linenr, $1 -> offset, ""), $1, $2, $4);
					 free_ast($3);}

	| identdecl funcp ')' ';'	 {$$ = adopt2(new astree(TOK_PROTOTYPE,
					 $1 -> filenr, $1 -> linenr, $1 -> offset, ""),$1,$2);
				  	 free_ast2($3,$4);}
	;


funcp	: '(' identdecl {$$ = adopt1_sym($1,$2,TOK_PARAMLIST);}
	| funcp ',' identdecl {$$ = adopt1($1,$3);}
	;

identdecl: basetype TOK_ARRAY TOK_IDENT
	{$2 = change_sym($3, TOK_DECLID) ;$$ = adopt2($2,$1,$3); }
	|  basetype TOK_IDENT 
	{$2 = change_sym($2, TOK_DECLID) ;$$ = adopt1($1,$2); } 
	;

block	: '{' '}' 	{$$ = change_sym($1, TOK_BLOCK); free_ast($2);}
	| blkstmts '}' 	{$$ = change_sym($1, TOK_BLOCK); free_ast($2);}
	| ';' 		{$$ = $1;}
	;

blkstmts: '{' statement {$$ = adopt1($1,$2);}
	| blkstmts statement {$$ = adopt1($1,$2);}
	;

statement: block	{$$ = $1;}
	| vardecl	{$$ = $1;}
	| while		{$$ = $1;}
	| ifelse	{$$ = $1;}
	| return	{$$ = $1;}
	| expr ';'	{$$ = $1; free_ast($2);}
	;

vardecl	: identdecl '=' expr ';'
	{$$ = adopt2_sym($2,$1,$3, TOK_VARDECL); free_ast($4);}
	;

while	: TOK_WHILE '(' expr ')' statement
	{$$ = adopt2($1,$3,$5); free_ast2($2,$4);}
	;

ifelse 	: TOK_IF '(' expr ')' statement %prec TOK_ELSE  
	{$$ = adopt2($1,$3,$5); free_ast2($2,$4);}
	| TOK_IF '(' expr ')' statement TOK_ELSE statement
	{$$ = adopt2(adopt1_sym($1,$3,TOK_IFELSE),$5,$7); free_ast2($2,$4); free_ast($6);}
	;

return	: TOK_RETURN expr ';' {$$ = adopt1($1,$2); free_ast($3);}
	| TOK_RETURN ';' {$$ = adopt1_sym($1, NULL, TOK_RETURNVOID); free_ast($2);}
	;

expr	: constant 		{$$ = $1;}
	| variable		{$$ = $1;}
	| '(' expr ')' 		{$$ = $2; free_ast2($1,$3);}
	| call			{$$ = $1;}
	| allocator 		{$$ = $1;}	
	| expr '=' expr 	 { $$ = adopt2 ($2, $1, $3);}
	| expr TOK_EQ expr       { $$ = adopt2 ($2, $1, $3); }
	| expr TOK_NE expr       { $$ = adopt2 ($2, $1, $3); }
	| expr TOK_LT expr       { $$ = adopt2 ($2, $1, $3); }
	| expr TOK_LE expr       { $$ = adopt2 ($2, $1, $3); }
	| expr TOK_GT expr       { $$ = adopt2 ($2, $1, $3); }
	| expr TOK_GE expr       { $$ = adopt2 ($2, $1, $3); }
	| expr '+' expr          { $$ = adopt2 ($2, $1, $3); }	
	| expr '-' expr      	 { $$ = adopt2 ($2, $1, $3); }
	| expr '*' expr      	 { $$ = adopt2 ($2, $1, $3); }
	| expr '/' expr      	 { $$ = adopt2 ($2, $1, $3); }
	| expr '%' expr      	 { $$ = adopt2 ($2, $1, $3); }
	| TOK_ORD expr      	 { $$ = adopt1 ($1, $2); }
	| TOK_CHR expr		 { $$ = adopt1 ($1, $2); }
	| '!' expr       	 { $$ = adopt1 ($1, $2); }
	| '+' expr %prec TOK_POS { $$ = adopt1_sym ($1,$2, TOK_POS); }
	| '-' expr %prec TOK_NEG { $$ = adopt1_sym ($1,$2, TOK_NEG);}
	;


allocator: TOK_NEW TOK_IDENT '(' ')' 	{$$ = $2 = change_sym($2, TOK_TYPEID);
					$$ = adopt1($1, $2);
				     	free_ast2($3,$4);} 
	 | TOK_NEW TOK_STRING '(' expr ')' {$$ = adopt1_sym($1,$4,TOK_NEWSTRING);
					   free_ast($2);free_ast($3);free_ast($5);}
	 | TOK_NEW basetype '[' expr ']' {$$ = adopt2_sym($1, $2, $4, TOK_NEWARRAY);
					 free_ast2($3,$5);}
	 ;

call    : TOK_IDENT '(' ')' {$$ = change_sym($2, TOK_CALL);free_ast($3);}
	| arg ')' {$$ = $1; free_ast($2);}
	;

arg     : TOK_IDENT '(' expr {$$ = adopt1(adopt1_sym($2,$1,TOK_CALL),$3);}
	| arg ',' expr {$$ = adopt1($1,$3);free_ast($2);}
	;

variable: TOK_IDENT {$$ = $1;}
	| expr '['expr ']' {$$ = adopt1(adopt1_sym($2,$1,TOK_INDEX),$3);free_ast($4);}
	| expr '.' TOK_IDENT 	{$3 = change_sym($3,TOK_FIELD);
				$$ = adopt2($2,$1, $3);}
	;


constant: TOK_INTCON {$$ = $1;}
	| TOK_CHARCON {$$ = $1;}
	| TOK_STRINGCON {$$ = $1;}
	| TOK_FALSE {$$ = $1;}
	| TOK_TRUE {$$ = $1;}
	| TOK_NULL {$$ = $1;}
	;

%%


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

/*
static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != nullptr);
   return result;
}
*/

