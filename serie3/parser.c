/*!
\file
\brief implementation of a top-down parser for Modula-2
\note This file must be extended.
*/

#include <stdio.h>
#include <assert.h>
#include "scanner.h"
#include "parser.h"
#include "diagnosis.h"

/*!
\brief a list of symbol names for output

The entries of this arrays are used in function #NEXT to print the name of a
just read token. Its indices match with the values of #yytokentype.

\warning This array must not be changed.
*/
const char* tokenNames[] = {
	"KEY_ARRAY", "KEY_BEGIN", "KEY_CHAR", "KEY_CONST", "KEY_DO", "KEY_ELSE",
	"KEY_ELSIF", "KEY_END", "KEY_FOR", "KEY_IF", "KEY_INTEGER",
	"KEY_MODULE", "KEY_OF", "KEY_PROCEDURE", "KEY_REAL", "KEY_REPEAT",
	"KEY_RETURN", "KEY_THEN", "KEY_TO", "KEY_TYPE", "KEY_UNTIL", "KEY_VAR",
	"KEY_WHILE", "ASSIGN", "OR", "AND", "EQ", "NE", "LE", "GE", "LEQ",
	"GEQ", "PLUS", "MINUS", "ASTERISK", "SLASH", "DIV", "MOD", "NOT",
	"SEMICOLON", "PERIOD", "COLON", "COMMA", "LPAREN", "RPAREN", "LBRACK",
	"RBRACK", "RANGE", "IDENT", "INTEGER", "REAL", "CHAR", "STRING",
	"END_OF_FILE"
};


/*!
\brief the current token

This variable holds the current token and is used to communicate between the
lexer and the syntax analyzer. It is set by #NEXT.
*/
yytokentype currentToken;


/*!
\brief current indentation

This variable holds the current indentation level. It is written by the
functions #entering and #leaving and read by #indent.
*/
unsigned int indent_current = 0;


/*!
\brief indentation step width

This variable sets the width of the indentation steps. With each call of
#entering, the indentation is incremented by this value. Likewise, each call of
#leaving decrements the indentation.
*/
const unsigned int indent_step = 3;


/*!
This function communicates with the generated scanner by calling #yylex to get
a new token. Its type is stored in #currentToken and printed to #yyout. If the
token has a value, it is also printed.

\pre File #yyout is opened.
\warning This function must not be changed.
*/
void NEXT() {
	assert(yyout);

	currentToken = yylex();

	print_current_token();
}


/*!
This function prints indentation to #yyout according to the currently set
indentation width.

\pre File #yyout is opened.
\warning This function must not be changed.
*/
void indent() {
	unsigned int i;

	assert(yyout);

	for (i = 0; i < indent_current; ++i) {
		if (i % indent_step == 0) {
			fprintf(yyout, "|");
		} else {
			fprintf(yyout, " ");
		}
	}
}


/*!
This function checks if current token equals given token. It is just a
placeholder to make the code of the syntax analysis more similar to textbook
top-down parsers.

\param s  a token type to match against
\return A nonzero value (true) if the tokens match, and 0 (false) if they do
not match.

\warning This function must not be changed
*/
int TEST(yytokentype s) {
	return (s == currentToken);
}


/*!
This function matches the current token and reads next token. If the tokens
do not match, an error is reported using #yyerror.

\param s  a token type to match against
\post The program may exit in case the given token does not match the current
token.

\warning This function must not be changed
*/
void MATCH(yytokentype s) {
	if (TEST(s)) {
		NEXT();
	} else {
		fprintf(stderr, "unexpected %s, expected %s\n", tokenNames[currentToken], tokenNames[s]);
		yyerror("syntax error");
	}
}


/*!
This function prints the name of an entered function (usually for a nonterminal
symbol) and increases the indentation.

\param s  name to print

\warning This function must not be changed
*/
void entering(char* s) {
	assert(s);
	indent();
	fprintf(yyout, "entering %s\n", s);
	indent_current += indent_step;
}

/*!
This function prints the name of a left function (usually for a nonterminal
symbol) and decreases the indentation.

\param s  name to print

\warning This function must not be changed
*/
void leaving(char* s) {
	assert(s);
	indent_current -= indent_step;
	indent();
	fprintf(yyout, "leaving %s\n", s);
}

/*!
This function is the starting point for a top-down parser for Modula-2. It
initializes #currentToken and calls the wrapper function for the start symbol
of the grammar, #module. The parser reads its input from #yyin and writes
output to #yyout.

\pre File #yyin and #yyout are opened.
\post This function only returns if no syntax error occurred.

\warning This function must not be changed
*/
void yyparse() {
	/* read first token */
	NEXT();
	/* process start symbol */
	module();
}


/*
 * please add your own code below this comment
 */

void print_current_token() {
	indent();
	fprintf(yyout, "read symbol in line %d:\t", yylineno);

	switch (currentToken) {
		case (CHAR):
		case (STRING):
		case (IDENT): {
			fprintf(yyout, "<%s (%s)> ", tokenNames[currentToken], yytext);
			break;
		}
		case (INTEGER): {
			fprintf(yyout, "<%s (%d)> ", tokenNames[currentToken], atoi(yytext));
			break;
		}
		case (REAL): {
			fprintf(yyout, "<%s (%.10f)> ", tokenNames[currentToken], atof(yytext));
			break;
		}
		default: {
			fprintf(yyout, "<%s> ", tokenNames[currentToken]);
		}
	}
	fprintf(yyout, "\n");
}

void print_tokens() {
	NEXT();
	while (currentToken != END_OF_FILE) {
		NEXT();
	}
	fprintf(yyout, "\n");
}

/*!
 * \verbatim
 * module ::= 'KEY_MODULE' 'IDENT' 'SEMICOLON' block 'KEY_END' 'IDENT' 'PERIOD'
 * \endverbatim
 */
void module() {
	entering("module");

	MATCH(KEY_MODULE);
	MATCH(IDENT);
	MATCH(SEMICOLON);

	block();

	MATCH(IDENT);
	MATCH(PERIOD);

	leaving("module");
}

void block() {
	entering("block");

	declaration();

	MATCH(KEY_BEGIN);
	MATCH(KEY_END);

	leaving("block");
}

void declaration() {
	entering("declaration");

	switch (currentToken) {
		case (KEY_CONST): {
			MATCH(KEY_CONST);
			constant_declaration();
			declaration();
		}
		case (KEY_TYPE): {
			MATCH(KEY_TYPE);
			type_declaration();
			declaration();
		}
		case (KEY_VAR): {
			MATCH(KEY_VAR);
			variable_declaration();
			declaration();
		}
		case (KEY_PROCEDURE): {
			procedure_declaration();
			declaration();
		}
		default: {}
	}

	leaving("declaration");
}

void constant_declaration() {
	if (currentToken == IDENT) {
		entering("constant declaration");

		MATCH(IDENT);
		MATCH(EQ);

		expression();

		MATCH(SEMICOLON);

		leaving("constant declaration");

		constant_declaration();
	}
}

void type_declaration() {
	if (currentToken == IDENT) {
		entering("type declaration");

		MATCH(IDENT);
		MATCH(EQ);

		type_denoter();

		MATCH(SEMICOLON);

		leaving("type declaration");

		type_declaration();
	}

}

void variable_declaration() {
	if (currentToken == IDENT) {
		entering("variable declaration");

		MATCH(IDENT);
		MATCH(COLON);

		type_denoter();

		MATCH(SEMICOLON);

		leaving("variable declaration");

		variable_declaration();
	}

}

void procedure_declaration() {
	entering("procedure declaration");

	MATCH(KEY_PROCEDURE);
	MATCH(IDENT);

	parameters();

	MATCH(COLON);

	type_denoter();

	MATCH(SEMICOLON);

	block();

	MATCH(IDENT);
	MATCH(SEMICOLON);

	leaving("procedure declaration");
}

void expression() {

}

void type_denoter() {
	switch (currentToken) {
		case (IDENT): {
			MATCH(IDENT);
			break;
		}
		case (KEY_INTEGER): {
			MATCH(KEY_INTEGER);
			break;
		}
		case (KEY_REAL): {
			MATCH(KEY_REAL);
			break;
		}
		case (KEY_CHAR): {
			MATCH(KEY_CHAR);
			break;
		}
		case (KEY_ARRAY): {
			MATCH(KEY_ARRAY);
			subrange();
			MATCH(KEY_OF);
			type_denoter();
			break;
		}
		default: {}
	}

}

void parameters() {
	entering("parameters");
	MATCH(LPAREN);

	parameter();

	MATCH(SEMICOLON);
	MATCH(RPAREN);

	leaving("parameters");
}

void parameter() {
	if (currentToken == KEY_VAR) {
		entering("parameter");

		MATCH(KEY_VAR);
		MATCH(IDENT);
		MATCH(COLON);

		type_denoter();
		leaving("parameter");

		parameter();
	}
}

void subrange() {
	MATCH(LBRACK);
	expression();
	MATCH(RANGE);
	expression();
	MATCH(RBRACK);
}
