%{
	
#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { lexer_useraction (); }

%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option verbose
%option warn

TOK_VOID				(void)
TOK_BOOL				(bool)
TOK_CHAR				(char)
TOK_INT					(int)
TOK_STRING				(string)
TOK_STRUCT				(struct)
TOK_IF					(if)
TOK_ELSE				(else)
TOK_WHILE				(while)
TOK_RETURN				(return)
TOK_FALSE				(false)
TOK_TRUE				(true)
TOK_NULL				(null)
TOK_ORD					(ord)
TOK_CHR					(chr)
TOK_NEW					(new)
TOK_ARRAY				("[]")
TOK_EQ					(==)
TOK_NE					(!=)
TOK_LE					(<=)
TOK_GE					(>=)
TOK_LT					(<)
TOK_GT					(>)

LETTER					[A-Za-z_]
DIGIT					[0-9]
TOK_IDENT				({LETTER}({LETTER}|{DIGIT})*)
TOK_INTCON				({DIGIT}+)
TOK_CHARCON				(’([^\\’\n]|\\[\\’"0nt])’)
TOK_STRINGCON				(\"([^\\"\n]|\\[\\’"0nt])*\")
BAD_TOK_IDENT				({DIGIT}+{TOK_IDENT})

%%

"#".*					{lexer_include();}
[ \t]+					{ }
\n					{lexer_newline();}

{TOK_VOID}				{return yylval_token(TOK_VOID);}
{TOK_BOOL}				{return yylval_token(TOK_BOOL);}
{TOK_CHAR}				{return yylval_token(TOK_CHAR);}
{TOK_INT}				{return yylval_token(TOK_INT);}
{TOK_STRING}				{return yylval_token(TOK_STRING);}
{TOK_STRUCT}				{return yylval_token(TOK_STRUCT);}
{TOK_IF}				{return yylval_token(TOK_IF);}
{TOK_ELSE}				{return yylval_token(TOK_ELSE);}
{TOK_WHILE}				{return yylval_token(TOK_WHILE);}
{TOK_RETURN}				{return yylval_token(TOK_RETURN);}
{TOK_FALSE}				{return yylval_token(TOK_FALSE);}
{TOK_TRUE}				{return yylval_token(TOK_TRUE);}
{TOK_NULL}				{return yylval_token(TOK_NULL);}
{TOK_ORD}				{return yylval_token(TOK_ORD);}
{TOK_CHR}				{return yylval_token(TOK_CHR);}
{TOK_NEW}				{return yylval_token(TOK_NEW);}

{TOK_IDENT}				{return yylval_token(TOK_IDENT);}
{TOK_INTCON}				{return yylval_token(TOK_INTCON);}
{TOK_CHARCON}				{return yylval_token(TOK_CHARCON);}
{TOK_STRINGCON}				{return yylval_token(TOK_STRINGCON);}

{TOK_ARRAY}				{return yylval_token(TOK_ARRAY);}
{TOK_EQ}				{return yylval_token(TOK_EQ);}
{TOK_NE}				{return yylval_token(TOK_NE);}
{TOK_LE}				{return yylval_token(TOK_LE);}
{TOK_GE}				{return yylval_token(TOK_GE);}
{TOK_LT}				{return yylval_token(TOK_LT);}
{TOK_GT}				{return yylval_token(TOK_GT);}
"="					{return yylval_token('=');}
"("					{return yylval_token('(');}
")"					{return yylval_token(')');}
"["					{return yylval_token('[');}
"]"					{return yylval_token(']');}
"{"					{return yylval_token('{');}
"}"					{return yylval_token('}');}
";"					{return yylval_token(';');}
","					{return yylval_token(',');}
"."					{return yylval_token('.');}
"+"					{return yylval_token('+');}
"-"					{return yylval_token('-');}
"*"					{return yylval_token('*');}
"/"					{return yylval_token('/');}
"%"					{return yylval_token('%');}
"!"					{return yylval_token('!');}

{BAD_TOK_IDENT}			{lexer_badtoken(yytext);
						return yylval_token(TOK_IDENT);}

.					{lexer_badchar(*yytext);}

%%
