%{
#include "k.h"
#include "yystype.h"

#include "diagnosis.h"
#include "scanner.h"
#include "symboltable.h"

extern kc::module root;
%}

%expect 0
%output "parser.cc"
%defines "parser.h"
%error-verbose
%locations

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

%token C_STRING C_CHAR IDENT C_INTEGER C_REAL

%type<yt_casestring> C_STRING IDENT
%type<yt_casestring> C_CHAR
%type<yt_integer> C_INTEGER
%type<yt_real> C_REAL

/* Nichtterminale */

%type<yt_module> module
%type<yt_block> block
%type<yt_declaration_list> declaration_list
%type<yt_statement_sequence> opt_begin_and_statement
%type<yt_declaration> declaration
%type<yt_constant_declaration_list> constant_declaration_list
%type<yt_type_declaration_list> type_declaration_list
%type<yt_variable_declaration_list> variable_declaration_list
%type<yt_constant_declaration> constant_declaration
%type<yt_type_declaration> type_declaration
%type<yt_variable_declaration> variable_declaration
%type<yt_procedure_declaration> procedure_declaration
%type<yt_parameter_list> parameters
%type<yt_parameter_list> opt_parameter_list
%type<yt_parameter_list> parameter_list
%type<yt_parameter> parameter
%type<yt_variable_designator> variable_designator
%type<yt_type_denoter> type_denoter
%type<yt_subrange> subrange
%type<yt_statement> statement
%type<yt_statement_sequence> statement_sequence
%type<yt_empty_statement> empty_statement
%type<yt_assignment_statement> assignment_statement
%type<yt_function_call> function_call
%type<yt_expression_list> opt_expression_list
%type<yt_expression_list> expression_list
%type<yt_return_statement> return_statement
%type<yt_if_statement> if_statement
%type<yt_elsif_list> ELSIF_list
%type<yt_opt_else> opt_ELSE
%type<yt_while_statement> while_statement
%type<yt_repeat_statement> repeat_statement
%type<yt_for_statement> for_statement
%type<yt_expression> expression
%type<yt_constant_literal> constant_literal

%%

module:
  KEY_MODULE { SymbolTable::pushScope(); }
  IDENT { SymbolTable::define($3->name, MODULE, @3); }
  SEMICOLON block
  IDENT { SymbolTable::use($7->name, @7); SymbolTable::popScope(); } PERIOD
    { root = $$ = kc::Module($3, $6); }
;

block:
  declaration_list opt_begin_and_statement KEY_END
    { $$ = kc::Block($1, $2); }
;

declaration_list:
  /* empty */
    { $$ = kc::Nildeclaration_list(); }
| declaration declaration_list
    { $$ = kc::Consdeclaration_list($1, $2); }
;

opt_begin_and_statement:
  /* empty */
    { $$ = kc::Nilstatement_sequence(); }
| KEY_BEGIN statement_sequence
    { $$ = $2; }
;

declaration:
  KEY_CONST constant_declaration_list
    { $$ = kc::ConstantDeclarationList($2); }
| KEY_TYPE type_declaration_list
    { $$ = kc::TypeDeclarationList($2); }
| KEY_VAR variable_declaration_list
    { $$ = kc::VariableDeclarationList($2); }
| procedure_declaration
    { $$ = kc::ProcedureDeclaration($1); }
;

constant_declaration_list:
  /* empty */
    { $$ = kc::Nilconstant_declaration_list(); }
| constant_declaration constant_declaration_list
    { $$ = kc::Consconstant_declaration_list($1, $2); }
;

type_declaration_list:
  /* empty */
    { $$ = kc::Niltype_declaration_list(); }
| type_declaration type_declaration_list
    { $$ = kc::Constype_declaration_list($1, $2); }
;

variable_declaration_list:
  /* empty */
    { $$ = kc::Nilvariable_declaration_list(); }
| variable_declaration variable_declaration_list
    { $$ = kc::Consvariable_declaration_list($1, $2); }
;

constant_declaration:
  IDENT EQ expression SEMICOLON
    { SymbolTable::define($1->name, CONSTANT, @1); }
    { $$ = kc::ConstantDeclaration($1, $3); }
;

type_declaration:
  IDENT EQ type_denoter SEMICOLON
    { SymbolTable::define($1->name, TYPE, @1); }
    { $$ = kc::TypeDeclaration($1, $3); }
;

variable_declaration:
  IDENT COLON type_denoter SEMICOLON
    { SymbolTable::define($1->name, VARIABLE, @1); }
    { $$ = kc::VariableDeclaration($1, $3); }
;

procedure_declaration:
  KEY_PROCEDURE IDENT
  { SymbolTable::define($2->name, PROCEDURE, @2); SymbolTable::pushScope(); }
  parameters COLON type_denoter SEMICOLON block IDENT SEMICOLON
  { SymbolTable::popScope(); SymbolTable::use($9->name, @9); }
  { $$ = Procedure($2, $4, $6, $8); }
;

parameters:
  LPAREN opt_parameter_list RPAREN
    { $$ = $2; }
;

opt_parameter_list:
  /* empty */
    { $$ = kc::Nilparameter_list(); }
| parameter_list
    { $$ = $1; }
;

parameter_list:
  parameter
    { $$ = kc::Consparameter_list($1, kc::Nilparameter_list()); }
  | parameter SEMICOLON parameter_list
    { $$ = kc::Consparameter_list($1, $3); }
;

parameter:
  KEY_VAR IDENT COLON type_denoter { SymbolTable::define($2->name, VARIABLE, @2); }
    { $$ = kc::Parameter($2, $4); }
;

variable_designator:
  IDENT { SymbolTable::use($1->name, @1); }
    { $$ = kc::VariableDesignator($1); }
| variable_designator LBRACK expression RBRACK
    { $$ = kc::IndexedVariableDesignator($1, $3); }
;

type_denoter:
  IDENT
    { $$ = kc::TypeIdent($1); }
| KEY_INTEGER
    { $$ = kc::TypeInteger(); }
| KEY_REAL
    { $$ = kc::TypeReal(); }
| KEY_CHAR
    { $$ = kc::TypeChar(); }
| KEY_ARRAY subrange KEY_OF type_denoter
    { $$ = kc::TypeArray($2, $4); }
;

subrange:
  LBRACK expression RANGE expression RBRACK
    { $$ = kc::Subrange($2, $4); }
;

statement:
  empty_statement
    { $$ = kc::EmptyStatement($1); }
| assignment_statement
    { $$ = kc::AssignmentStatement($1); }
| function_call
    { $$ = kc::FunctionCallStatement($1); }
| return_statement
    { $$ = kc::ReturnStatement($1); }
| if_statement
    { $$ = kc::IfStatement($1); }
| while_statement
    { $$ = kc::WhileStatement($1); }
| repeat_statement
    { $$ = kc::RepeatStatement($1); }
| for_statement
    { $$ = kc::ForStatement($1); }
;

statement_sequence:
  statement
    { $$ = kc::Consstatement_sequence($1, kc::Nilstatement_sequence()); }
| statement SEMICOLON statement_sequence
    { $$ = kc::Consstatement_sequence($1, $3); }
;

empty_statement:
  /* empty */
    { $$ = kc::Empty(); }
;

assignment_statement:
  variable_designator ASSIGN expression
    { $$ = kc::Assignment($1, $3); }
;

function_call:
  IDENT { SymbolTable::use($1->name, @1); } LPAREN opt_expression_list RPAREN
    { $$ = kc::FunctionCall($1, $4); }
;

opt_expression_list:
  /* empty */
    { $$ = kc::Nilexpression_list(); }
| expression_list
    { $$ = $1; }
;

expression_list:
  expression
    { $$ = kc::Consexpression_list($1, kc::Nilexpression_list()); }
| expression COMMA expression_list
    { $$ = kc::Consexpression_list($1, $3); }
;

return_statement:
  KEY_RETURN expression
    { $$ = kc::Return($2); }
;

if_statement:
  KEY_IF expression KEY_THEN statement_sequence ELSIF_list opt_ELSE KEY_END
    { $$ = kc::If($2, $4, $5, $6); }
;

ELSIF_list:
  /* empty */
    { $$ = kc::Nilelsif_list(); }
| KEY_ELSIF expression KEY_THEN statement_sequence ELSIF_list
    { $$ = kc::Conselsif_list(kc::Elsif($2, $4), $5); }
;

opt_ELSE:
  /* empty */
    { $$ = kc::NoElse(); }
| KEY_ELSE statement_sequence
    { $$ = kc::Else($2); }
;

while_statement:
  KEY_WHILE expression KEY_DO statement_sequence KEY_END
    { $$ = kc::While($2, $4); }
;

repeat_statement:
  KEY_REPEAT statement_sequence KEY_UNTIL expression
    { $$ = kc::Repeat($2, $4); }
;

for_statement:
  KEY_FOR variable_designator ASSIGN expression KEY_TO expression KEY_DO
  statement_sequence KEY_END
    { $$ = For($2, $4, $6, $8); }
;

expression:
  LPAREN expression RPAREN
    { $$ = $2; }
| NOT expression
    { $$ = kc::Not($2); }
| variable_designator
    { $$ = kc::ExVariableDesignator($1); }
| function_call
    { $$ = kc::ExFunctionCall($1); }  
| constant_literal
    { $$ = kc::ConstantLiteral($1); }
| expression EQ expression
    { $$ = kc::Eq($1, $3); }
| expression NE expression
    { $$ = kc::Ne($1, $3); }
| expression LE expression
    { $$ = kc::Le($1, $3); }
| expression GE expression
    { $$ = kc::Ge($1, $3); }
| expression LEQ expression
    { $$ = kc::Leq($1, $3); }
| expression GEQ expression
    { $$ = kc::Geq($1, $3); }
| expression PLUS expression
    { $$ = kc::Plus($1, $3); }
| expression MINUS expression
    { $$ = kc::Minus($1, $3); }
| expression OR expression
    { $$ = kc::Or($1, $3); }
| expression ASTERISK expression
    { $$ = kc::Asterisk($1, $3); }
| expression SLASH expression
    { $$ = kc::Slash($1, $3); }
| expression DIV expression
    { $$ = kc::Div($1, $3); }
| expression MOD expression
    { $$ = kc::Mod($1, $3); }
| expression AND expression
    { $$ = kc::And($1, $3); }
;

constant_literal:
  C_INTEGER
    { $$ = kc::IntegerConstant($1); }
| C_REAL
    { $$ = kc::RealConstant($1); }
| C_CHAR
    { $$ = kc::CharConstant($1); }
| C_STRING
    { $$ = kc::StringConstant($1); }
;

%%
