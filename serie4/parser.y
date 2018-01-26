/*!
\file
\brief a parser for Modula-2
\note This file must be extended according to Modula's grammar.
*/

%{
#include "diagnosis.h"
#include "scanner.h"
#include "symboltable.h"
%}

%expect 0
%output "parser.cc"
%defines "parser.h"
%error-verbose
%locations

%union {
    char* string_constant;  // STRING, IDENT
    char char_constant;     // CHAR
    int integer_constant;   // INTEGER
    double real_constant;   // REAL
}

/* here go the token and type definitions as well as precedences */

/* Schlüsselworte */
%token KEY_ARRAY KEY_BEGIN KEY_CHAR KEY_CONST KEY_DO KEY_ELSE KEY_ELSIF
%token KEY_END KEY_FOR KEY_IF KEY_INTEGER KEY_MODULE KEY_OF KEY_PROCEDURE
%token KEY_REAL KEY_REPEAT KEY_RETURN KEY_THEN KEY_TO KEY_TYPE KEY_UNTIL
%token KEY_VAR KEY_WHILE

/* Operatoren */
%token ASSIGN OR AND EQ NE LE GE LEQ GEQ PLUS MINUS ASTERISK SLASH DIV MOD NOT

/* Trennzeichen */
%token SEMICOLON PERIOD COLON COMMA LPAREN RPAREN LBRACK RBRACK RANGE

/* Konstanten */
%token IDENT INTEGER REAL CHAR STRING

%type <string_constant>  STRING IDENT
%type <char_constant>    CHAR
%type <integer_constant> INTEGER
%type <real_constant>    REAL

%%
/* here goes the grammar */

module:
	KEY_MODULE { SymbolTable::pushScope(); }
	IDENT { SymbolTable::define($3, MODULE, @3); free($3); }
	SEMICOLON
	block
	IDENT { SymbolTable::use($7, @7); SymbolTable::popScope(); free($7); } PERIOD
;

block:
	declaration KEY_END
|	declaration KEY_BEGIN statement_sequence KEY_END
;

declaration:
	KEY_CONST constant_declaration declaration
|	KEY_TYPE type_declaration declaration
|	KEY_VAR variable_declaration
|	procedure_declaration
|	%empty
;

statement_sequence:
	%empty
;

constant_declaration:
	%empty
;

type_declaration:
	%empty
;

variable_declaration:
	%empty
;

procedure_declaration:
	KEY_PROCEDURE
	IDENT
	SEMICOLON
;

%%

