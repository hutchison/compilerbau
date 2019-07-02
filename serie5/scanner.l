/* THIS FILE IS PART OF THE ASSIGNMENT AND MUST NOT BE CHANGED! */

%option noyywrap
%option outfile="scanner.cc" header-file="scanner.h"
%option yylineno

%{
#include <string>
#include "k.h"
#include "yystype.h"
#include "parser.h"
#include "diagnosis.h"

int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
  yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
  yycolumn += yyleng;
%}

digit [0-9]
letter [a-zA-Z]
character [^']
stringelement [^"]

%x COMMENT

%%

"(*"                           { BEGIN(COMMENT); }
<COMMENT>"*)"                  { BEGIN(INITIAL); }
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

"'"({character}|"\"")"'"       { std::string temp(yytext);
                                 yylval.yt_casestring = kc::mkcasestring(temp.substr(1,1).c_str());
                                 return C_CHAR; }
"\""({stringelement})*"\""     { std::string temp(yytext);
                                 yylval.yt_casestring = kc::mkcasestring(temp.substr(1, temp.length()-2).c_str());
                                 return C_STRING; }
{letter}({letter}|{digit})*    { yylval.yt_casestring = kc::mkcasestring(yytext);
                                 return IDENT; }
{digit}({digit})*              { yylval.yt_integer = kc::mkinteger(atoi(yytext));
                                 return C_INTEGER; }
{digit}({digit})*"."({digit})* { yylval.yt_real = kc::mkreal(atof(yytext));
                                 return C_REAL; }

[\n\r]                         { yycolumn = 1; /* skip whitespace */ }
[ \t]                          { /* skip whitespace */ }

.                              { yyerror("lexical error"); }

%%

