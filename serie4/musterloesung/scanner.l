/*!
\file
\brief a scanner for Modula-2
\note This file must not be changed.
*/

%option noyywrap
%option outfile="scanner.cc" header-file="scanner.h"
%option yylineno

%{
#include "parser.h"
#include "diagnosis.h"

/// the column of #yytext in #yyin
int yycolumn = 1;

/*!
\brief This macro is executed prior to the matched rule's action.

We use this macro to set set #yylloc to the positions of #yytext. It further
manages the current column number #yycolumn. See Flex's manual
http://flex.sourceforge.net/manual/Misc-Macros.html for more information on
the macro.
*/
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
  yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
  yycolumn += yyleng;

/// the depth of the comments
int comment_depth = 0;
%}

digit [0-9]
letter [a-zA-Z]
character [^'\n\r]
stringelement [^"]

%x COMMENT

%%

"(*"                           { BEGIN(COMMENT); ++comment_depth; }
<COMMENT>"(*"                  { BEGIN(COMMENT); ++comment_depth; }
<COMMENT>"*)"                  { if (--comment_depth == 0) BEGIN(INITIAL); }
<COMMENT>[\n\r\t ]             { /* skip whitespace */ }
<COMMENT>.                     { /* ignore comments */ }

"ARRAY"                        { return KEY_ARRAY; }
"BEGIN"                        { return KEY_BEGIN; }
"CHAR"                         { return KEY_CHAR; }
"CONST"                        { return KEY_CONST; }
"DO"                           { return KEY_DO; }
"ELSE"                         { return KEY_ELSE; }
"ELSIF"                        { return KEY_ELSIF; }
"END"                          { return KEY_END; }
"FOR"                          { return KEY_FOR; }
"IF"                           { return KEY_IF; }
"INTEGER"                      { return KEY_INTEGER; }
"MODULE"                       { return KEY_MODULE; }
"OF"                           { return KEY_OF; }
"PROCEDURE"                    { return KEY_PROCEDURE; }
"REAL"                         { return KEY_REAL; }
"REPEAT"                       { return KEY_REPEAT; }
"RETURN"                       { return KEY_RETURN; }
"THEN"                         { return KEY_THEN; }
"TO"                           { return KEY_TO; }
"TYPE"                         { return KEY_TYPE; }
"UNTIL"                        { return KEY_UNTIL; }
"VAR"                          { return KEY_VAR; }
"WHILE"                        { return KEY_WHILE; }

":="                           { return ASSIGN; }
"|"|"OR"                       { return OR; }
"&"|"AND"                      { return AND; }
"="                            { return EQ; }
"<>"|"#"                       { return NE; }
"<"                            { return LE; }
">"                            { return GE; }
"<="                           { return LEQ; }
">="                           { return GEQ; }
"+"                            { return PLUS; }
"-"                            { return MINUS; }
"*"                            { return ASTERISK; }
"/"                            { return SLASH; }
"DIV"                          { return DIV; }
"MOD"                          { return MOD; }
"~"|"NOT"                      { return NOT; }

";"                            { return SEMICOLON; }
"."                            { return PERIOD; }
":"                            { return COLON; }
","                            { return COMMA; }
"("                            { return LPAREN; }
")"                            { return RPAREN; }
"["                            { return LBRACK; }
"]"                            { return RBRACK; }
".."                           { return RANGE; }

"'"({character}|"\"")"'"       { yylval.char_constant = yytext[1];
                                 return CHAR; }
"\""({stringelement})*"\""     { yylval.string_constant = (char*)calloc(yyleng-1, sizeof(char));
                                 if (!yylval.string_constant) yyerror("could not allocate memory");
                                 memcpy(yylval.string_constant, yytext+1, yyleng-2);
                                 return STRING; }
{letter}({letter}|{digit})*    { yylval.string_constant = (char*)malloc((yyleng+1) * sizeof(char));
                                 if (!yylval.string_constant) yyerror("could not allocate memory");
                                 strcpy(yylval.string_constant, yytext);
                                 return IDENT; }
{digit}({digit})*              { yylval.integer_constant = atoi(yytext);
                                 return INTEGER; }
{digit}({digit})*"."({digit})* { yylval.real_constant = atof(yytext);
                                 return REAL; }

[\n\r]                         { yycolumn = 1; /* skip whitespace */ }
[ \t]                          { /* skip whitespace */ }

.                              { yyerror("lexical error"); }

%%
