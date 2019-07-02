module:
  Module(casestring block)
;

block:
  Block(declaration_list statement_sequence)
;

declaration_list:
  list declaration
;

declaration:
  ConstantDeclarationList(constant_declaration_list)
| TypeDeclarationList(type_declaration_list)
| VariableDeclarationList(variable_declaration_list)
| ProcedureDeclaration(procedure_declaration)
;

constant_declaration_list:
  list constant_declaration
;

constant_declaration:
  ConstantDeclaration(casestring expression)
;

type_declaration_list:
  list type_declaration
;

type_declaration:
  TypeDeclaration(casestring type_denoter)
;

variable_declaration_list:
  list variable_declaration
;

variable_declaration:
  VariableDeclaration(casestring type_denoter)
;

procedure_declaration:
  Procedure(casestring parameter_list type_denoter block)
;

parameter_list:
  list parameter
;

parameter:
  Parameter(casestring type_denoter)
;

variable_designator:
  VariableDesignator(casestring)
| IndexedVariableDesignator(variable_designator expression)
;

type_denoter:
  TypeIdent(casestring)
| TypeInteger()
| TypeReal()
| TypeChar()
| TypeArray(subrange type_denoter)
;

subrange:
  Subrange(expression expression)
;

statement:
  EmptyStatement(empty_statement)
| AssignmentStatement(assignment_statement)
| FunctionCallStatement(function_call)
| ReturnStatement(return_statement)
| IfStatement(if_statement)
| WhileStatement(while_statement)
| RepeatStatement(repeat_statement)
| ForStatement(for_statement)
;

empty_statement:
  Empty()
;

assignment_statement:
  Assignment(variable_designator expression)
;

function_call:
  FunctionCall(casestring expression_list)
;

return_statement:
  Return(expression)
;

if_statement:
  If(expression statement_sequence elsif_list opt_else)
;

elsif_list:
  list elsif
;

elsif:
  Elsif(expression statement_sequence)
;

opt_else:
  NoElse()
| Else(statement_sequence)
;

while_statement:
  While(expression statement_sequence)
;

repeat_statement:
  Repeat(statement_sequence expression)
;

for_statement:
  For(variable_designator expression expression statement_sequence)
;

expression_list:
  list expression
;

statement_sequence:
  list statement
;

expression:
  Not(expression)
| ExVariableDesignator(variable_designator)
| ExFunctionCall(function_call)
| ConstantLiteral(constant_literal)
| Eq(expression expression)
| Ne(expression expression)
| Le(expression expression)
| Ge(expression expression)
| Leq(expression expression)
| Geq(expression expression)
| Plus(expression expression)
| Minus(expression expression)
| Or(expression expression)
| Asterisk(expression expression)
| Slash(expression expression)
| Div(expression expression)
| Mod(expression expression)
| And(expression expression)
;

constant_literal:
  IntegerConstant(integer)
| RealConstant(real)
| CharConstant(casestring)
| StringConstant(casestring)
;
