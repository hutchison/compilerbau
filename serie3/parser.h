/*!
\file
\brief definition of a top-down parser for Modula-2
\note This file must be extended.
*/

#ifndef _PARSER_H
#define _PARSER_H

/*!
\brief a list of all tokens (to be used as return values in Flex)

The entries can be used as indices for the array #tokenNames.

\warning This enumeration must not be changed.
*/
typedef enum {
	KEY_ARRAY, KEY_BEGIN, KEY_CHAR, KEY_CONST, KEY_DO, KEY_ELSE, KEY_ELSIF,
	KEY_END, KEY_FOR, KEY_IF, KEY_INTEGER, KEY_MODULE, KEY_OF,
	KEY_PROCEDURE, KEY_REAL, KEY_REPEAT, KEY_RETURN, KEY_THEN, KEY_TO,
	KEY_TYPE, KEY_UNTIL, KEY_VAR, KEY_WHILE, ASSIGN, OR, AND, EQ, NE, LE,
	GE, LEQ, GEQ, PLUS, MINUS, ASTERISK, SLASH, DIV, MOD, NOT, SEMICOLON,
	PERIOD, COLON, COMMA, LPAREN, RPAREN, LBRACK, RBRACK, RANGE, IDENT,
	INTEGER, REAL, CHAR, STRING, END_OF_FILE
} yytokentype;

void NEXT();                /*!< \brief read next token */
int TEST(yytokentype s);    /*!< \brief check current token against expected */
void MATCH(yytokentype s);  /*!< \brief match current token against expected */

void entering(char* s);     /*!< \brief announce entering a nonterminal rule */
void leaving(char* s);      /*!< \brief announce leaving a nonterminal rule */
void indent();              /*!< \brief organize proper indentation */

void yyparse();             /*!< \brief parse the file #yyin using #yylex */

/*
 * please add your own code below this comment
 */

void print_tokens();
void print_current_token();
void module();
void block();
void declaration();
void constant_declaration();
void type_declaration();
void variable_declaration();
void procedure_declaration();
void parameters();
void parameter();
void variable_designator();
void variable_designator_brackets();
void type_denoter();
void subrange();
void statement();
void statement_sequence();
void empty_statement();
void assignment_statement();
void function_call();
void return_statement();
void if_statement();
void elsif_statement();
void else_statement();
void while_statement();
void repeat_statement();
void for_statement();
void expression();
void expression1();
void constant_literal();

#endif
