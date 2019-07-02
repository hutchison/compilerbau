#ifndef YYSTYPE_HEADER
#define YYSTYPE_HEADER
union KC_YYSTYPE {
    kc::nocasestring yt_nocasestring;
    kc::casestring yt_casestring;
    kc::real yt_real;
    kc::integer yt_integer;
    kc::voidptr yt_voidptr;
    kc::module yt_module;
    kc::block yt_block;
    kc::declaration_list yt_declaration_list;
    kc::declaration yt_declaration;
    kc::constant_declaration_list yt_constant_declaration_list;
    kc::constant_declaration yt_constant_declaration;
    kc::type_declaration_list yt_type_declaration_list;
    kc::type_declaration yt_type_declaration;
    kc::variable_declaration_list yt_variable_declaration_list;
    kc::variable_declaration yt_variable_declaration;
    kc::procedure_declaration yt_procedure_declaration;
    kc::parameter_list yt_parameter_list;
    kc::parameter yt_parameter;
    kc::variable_designator yt_variable_designator;
    kc::type_denoter yt_type_denoter;
    kc::subrange yt_subrange;
    kc::statement yt_statement;
    kc::empty_statement yt_empty_statement;
    kc::assignment_statement yt_assignment_statement;
    kc::function_call yt_function_call;
    kc::return_statement yt_return_statement;
    kc::if_statement yt_if_statement;
    kc::elsif_list yt_elsif_list;
    kc::elsif yt_elsif;
    kc::opt_else yt_opt_else;
    kc::while_statement yt_while_statement;
    kc::repeat_statement yt_repeat_statement;
    kc::for_statement yt_for_statement;
    kc::expression_list yt_expression_list;
    kc::statement_sequence yt_statement_sequence;
    kc::expression yt_expression;
    kc::constant_literal yt_constant_literal;
};
#define YYSTYPE KC_YYSTYPE
#endif // YYSTYPE_HEADER
