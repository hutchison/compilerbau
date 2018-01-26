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
    char* string_constant;
    char char_constant;
    int integer_constant;
    double real_constant;
}

/* Schlüsselworte */

%token KEY_ARRAY KEY_BEGIN KEY_CHAR KEY_CONST KEY_DO KEY_ELSE KEY_ELSIF KEY_END
%token KEY_FOR KEY_IF KEY_INTEGER KEY_MODULE KEY_OF KEY_PROCEDURE KEY_REAL
%token KEY_REPEAT KEY_RETURN KEY_THEN KEY_TO KEY_TYPE KEY_UNTIL KEY_VAR
%token KEY_WHILE

/* Operatoren */

%right ASSIGN
%left OR AND
%left EQ NE
%left LE GE LEQ GEQ
%left PLUS MINUS
%left ASTERISK SLASH DIV MOD
%right NOT

/* Trennzeichen */

%token SEMICOLON PERIOD COLON COMMA LPAREN RPAREN LBRACK RBRACK RANGE

/* Konstanten */

%token STRING CHAR IDENT INTEGER REAL

%type<string_constant> STRING IDENT
%type<char_constant> CHAR
%type<integer_constant> INTEGER
%type<real_constant> REAL

%%

module:
  KEY_MODULE { SymbolTable::pushScope(); }
  IDENT { SymbolTable::define($3, MODULE, @3); free($3); }
  SEMICOLON block
  IDENT { SymbolTable::use($7, @7); SymbolTable::popScope(); free($7); } PERIOD
;

block:
  declaration_list opt_begin_and_statement KEY_END
;

declaration_list:
  /* empty */
| declaration declaration_list
;

opt_begin_and_statement:
  /* empty */
| KEY_BEGIN statement_sequence
;

declaration:
  KEY_CONST constant_declaration_list
| KEY_TYPE type_declaration_list
| KEY_VAR variable_declaration_list
| procedure_declaration
;

constant_declaration_list:
  /* empty */
| constant_declaration constant_declaration_list
;

type_declaration_list:
  /* empty */
| type_declaration type_declaration_list
;

variable_declaration_list:
  /* empty */
| variable_declaration variable_declaration_list
;

constant_declaration:
  IDENT EQ expression SEMICOLON
  { SymbolTable::define($1, CONSTANT, @1); free($1); }
;

type_declaration:
  IDENT EQ type_denoter SEMICOLON
  { SymbolTable::define($1, TYPE, @1); free($1); }
;

variable_declaration:
  IDENT COLON type_denoter SEMICOLON
  { SymbolTable::define($1, VARIABLE, @1); free($1); }
;

procedure_declaration:
  KEY_PROCEDURE IDENT
  { SymbolTable::define($2, PROCEDURE, @2); SymbolTable::pushScope(); free($2); }
  parameters COLON type_denoter SEMICOLON block IDENT
  { SymbolTable::popScope(); SymbolTable::use($9, @9); free($9); } SEMICOLON
;

parameters:
  LPAREN opt_parameter_list RPAREN
;

opt_parameter_list:
  /* empty */
| parameter_list
;

parameter_list:
  parameter
| parameter SEMICOLON parameter_list
;

parameter:
  KEY_VAR IDENT COLON type_denoter
  { SymbolTable::define($2, VARIABLE, @2); free($2); }
;

variable_designator:
  IDENT { SymbolTable::use($1, @1); free($1); }
| variable_designator LBRACK expression RBRACK
;

type_denoter:
  IDENT { SymbolTable::use($1, @1); free($1); }
| KEY_INTEGER
| KEY_REAL
| KEY_CHAR
| KEY_ARRAY subrange KEY_OF type_denoter;
;

subrange:
  LBRACK expression RANGE expression RBRACK
;

statement:
  empty_statement
| assignment_statement
| function_call
| return_statement
| if_statement
| while_statement
| repeat_statement
| for_statement
;

statement_sequence:
  statement
| statement SEMICOLON statement_sequence
;

empty_statement:
  /* empty */
;

assignment_statement:
  variable_designator ASSIGN expression
;

function_call:
  IDENT { SymbolTable::use($1, @1); free($1); } LPAREN opt_expression_list RPAREN
;

opt_expression_list:
  /* empty */
| expression_list
;

expression_list:
  expression
| expression COMMA expression_list
;

return_statement:
  KEY_RETURN expression
;

if_statement:
  KEY_IF expression KEY_THEN statement_sequence ELSIF_list opt_ELSE KEY_END
;

ELSIF_list:
  /* empty */
| KEY_ELSIF expression KEY_THEN statement_sequence ELSIF_list
;

opt_ELSE:
  /* empty */
| KEY_ELSE statement_sequence
;

while_statement:
  KEY_WHILE expression KEY_DO statement_sequence KEY_END
;

repeat_statement:
  KEY_REPEAT statement_sequence KEY_UNTIL expression
;

for_statement:
  KEY_FOR variable_designator ASSIGN expression KEY_TO expression KEY_DO
  statement_sequence KEY_END
;

expression:
  LPAREN expression RPAREN
| NOT expression
| variable_designator
| function_call
| constant_literal
| expression EQ expression
| expression NE expression
| expression LE expression
| expression GE expression
| expression LEQ expression
| expression GEQ expression
| expression PLUS expression
| expression MINUS expression
| expression OR expression
| expression ASTERISK expression
| expression SLASH expression
| expression DIV expression
| expression MOD expression
| expression AND expression
;

constant_literal:
  INTEGER
| REAL
| CHAR
| STRING
;

%%
