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

%right  '='
%left   '+' '-'
%left   '*' '/'
%right  '^'
%right  POS "u+" NEG "u-"

%start  program


%%

program : stmtseq               { $$ = $1; }
        ;

stmtseq : stmtseq expr ';'      { free_ast ($3); $$ = adopt1 ($1, $2); }
        | stmtseq error ';'     { free_ast ($3); $$ = $1; }
        | stmtseq ';'           { free_ast ($2); $$ = $1; }
        |                       { $$ = new_parseroot(); }
        ;

expr    : expr '=' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '+' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '-' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '*' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '/' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '^' expr         { $$ = adopt2 ($2, $1, $3); }
        | '+' expr %prec POS    { $$ = adopt1sym ($1, $2, POS); }
        | '-' expr %prec NEG    { $$ = adopt1sym ($1, $2, NEG); }
        | '(' expr ')'          { free_ast2 ($1, $3); $$ = $2; }
        | TOK_IDENT                 { $$ = $1; }
        | NUMBER                { $$ = $1; }
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

