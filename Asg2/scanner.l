%{
#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { scanner_useraction (); }
#define IGNORE(THING)   { }

%}

%option 8bit
%option debug
%option ecs
%option nodefault
%option nounput
%option noyywrap
%option perf-report
%option verbose


TOK_LT		(<)
TOK_GT		(>)
TOK_NE		(!=)
TOK_LE		(<=)
TOK_EQ		(==)
TOK_GE		(>=)
TOK_ARRAY	("[]")
TOK_ELSE	(else)
TOK_IF		(if)
TOK_INT		(int)
TOK_NEW		(new)
TOK_NULL	(null)
TOK_RETURN	(return)
TOK_STRING	(string)
TOK_STRUCT	(struct)
TOK_VOID	(void)
TOK_WHILE	(while)
TOK_ORD		(ord)
TOK_CHR		(chr)

LETTER          [A-Za-z_]
DIGIT           [0-9]
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)

TOK_IDENT       ({LETTER}({LETTER}|{DIGIT})*)
TOK_INTCON	({DIGIT}+)
TOK_CHARCON	(’([^\\’\n]|\\[\\’"0nt])’)
TOK_STRINGCON	(\"([^\\"\n]|\\[\\’"0nt])*\")

%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space); }
\n              { scanner_newline(); }

{TOK_LT}	{ return yylval_token(TOK_LT);}
{TOK_GT}	{ return yylval_token(TOK_GT);}
{TOK_NE}	{ return yylval_token(TOK_NE);}
{TOK_LE}	{ return yylval_token(TOK_LE);}
{TOK_EQ}	{ return yylval_token(TOK_EQ);}
{TOK_GE}	{ return yylval_token(TOK_GE);}
{TOK_ARRAY}	{ return yylval_token(TOK_ARRAY);}
{TOK_ELSE}	{ return yylval_token(TOK_ELSE);}
{TOK_IF}	{ return yylval_token(TOK_IF);}
{TOK_INT}	{ return yylval_token(TOK_INT);}
{TOK_NEW}	{ return yylval_token(TOK_NEW);}
{TOK_NULL}	{ return yylval_token(TOK_NULL);}
{TOK_RETURN}	{ return yylval_token(TOK_RETURN);}
{TOK_STRING}	{ return yylval_token(TOK_STRING);}
{TOK_STRUCT}	{ return yylval_token(TOK_STRUCT);}
{TOK_VOID}	{ return yylval_token(TOK_VOID);}
{TOK_WHILE}	{ return yylval_token(TOK_WHILE);}
{TOK_IDENT}     { return yylval_token(TOK_IDENT);}
{TOK_INTCON}	{ return yylval_token(TOK_INTCON);}
{TOK_CHARCON}	{ return yylval_token(TOK_CHARCON);}
{TOK_STRINGCON}	{ return yylval_token(TOK_STRINGCON);}
{TOK_ORD}	{ return yylval_token(TOK_ORD);}
{TOK_CHR}	{ return yylval_token(TOK_CHR);}

"="             { return yylval_token('='); }
"+"             { return yylval_token('+'); }
"-"             { return yylval_token('-'); }
"*"             { return yylval_token('*'); }
"/"             { return yylval_token('/'); }
"^"             { return yylval_token('^'); }
"("             { return yylval_token('('); }
")"             { return yylval_token(')'); }
";"             { return yylval_token(';'); }
"!"		{ return yylval_token('!'); }
"%"		{ return yylval_token('%'); }
","		{ return yylval_token(','); }


{NOTNUMBER}     { scanner_badtoken (yytext);
                  return yylval_token (NUMBER); }

.               { scanner_badchar (*yytext); }

%%

RCSC("$Id: scanner.l,v 1.3 2013-10-15 16:37:56-07 - - $")

