#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "buffer.h"
#include "tokens.h"
#include "scanner.h"
#include "diagnosis.h"


int main(int argc, char* argv[]) {
	int i;
	int keyword_index;

	/* initialize global variables */
	yyin = stdin;
	yyout = stdout;
	buffer_init();

	/* process command line parameters for input and output */
	if (argc > 3) {
		yyerror("wrong number of parameters");
	}
	if (argc > 1) {
		yyin = fopen(argv[1], "r");
		if (yyin == NULL) {
			yyerror("cannot open file for reading");
		}
	}
	if (argc > 2) {
		yyout = fopen(argv[2], "w");
		if (yyout == NULL) {
			yyerror("cannot open file for writing");
		}
	}

	next_char();
	while (ch != EOF) {
		if (ch == '(') {
			next_char();
			if (ch == '*') { /* Kommentarmodus */
				next_char();

				while (1) {
					next_char();

					if (ch == EOF) {
						yyerror("comment ended unexpectedly with EOF");
					} else if (ch == '*') {
						next_char();
						if (ch == EOF) {
							yyerror("comment ended unexpectedly with EOF");
						} else if (ch == ')') {
							break;
						}
					}
				}
			} else {
				append(LPAREN);
				buffer_reset();
				continue;
			}
		} else if (isalpha(ch)) {
			scanID();

			keyword_index = iskeyword(yytext);
			if (keyword_index >= 0) {
				append(keyword_index);
			} else {
				append(IDENT);
			}

			buffer_reset();
			continue;
		} else if (isdigit(ch)) {
			i = scanNUMBER();

			if (i == 0) {
				append(INTEGER);
			} else {
				append(REAL);
			}

			buffer_reset();
			continue;
		} else if (ch == ':') { /* Sonderfall ASSIGN UND COLON */
			next_char();
			if (ch == '=') {
				append(ASSIGN);
			} else {
				append(COLON);
				buffer_reset();
				continue;
			}
		} else if (ch == '<') {
			next_char();
			if (ch == '>') {
				append(NE);
			} else if (ch == '=') {
				append(LEQ);
			} else {
				append(LE);
				buffer_reset();
				continue;
			}
		} else if (ch == '>') {
			next_char();
			if (ch == '=') {
				append(GEQ);
			} else {
				append(GE);
				buffer_reset();
				continue;
			}
		} else if (ch == '.') { /* Sonderfall RANGE UND PERIOD */
			next_char();
			if (ch == '.') {
				append(RANGE);
			} else {
				append(PERIOD);
				buffer_reset();
				continue;
			}
		} else {
			switch (ch) {
				case '"':
					scanSTRING();
					append(STRING);
					break;
				case '\'':
					scanCHAR();
					append(CHAR);
					break;
				case '|':
					append(OR);
					break;
				case '&':
					append(AND);
					break;
				case '#':
					append(NE);
					break;
				case '=':
					append(EQ);
					break;
				case '+':
					append(PLUS);
					break;
				case '-':
					append(MINUS);
					break;
				case '*':
					append(ASTERISK);
					break;
				case '/':
					append(SLASH);
					break;
				case '~':
					append(NOT);
					break;
				case ';':
					append(SEMICOLON);
					break;
				/* PERIOD: Sonderfall mit RANGE */
				/* COLON: Sonderfall mit ASSIGN */
				case ',':
					append(COMMA);
					break;
				/* LPAREN: Sonderfall mit Kommentar */
				case ')':
					append(RPAREN);
					break;
				case '[':
					append(LBRACK);
					break;
				case ']':
					append(RBRACK);
					break;
				default:
					break;
			}
		}

		buffer_reset();
		next_char();
	}

	output_token_list();
	delete_token_list();

	buffer_destroy();

	fclose(yyin);
	fclose(yyout);

	return 0;
}
