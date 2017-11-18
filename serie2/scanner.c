#include <ctype.h>
#include "buffer.h"
#include "scanner.h"
#include "diagnosis.h"

int yylineno = 1;

char next_char() {
	ch = fgetc(yyin);
	if (ch == '\n') {
		yylineno += 1;
	}
	return ch;
}

void scanID() {
	while (isalpha(ch) || isdigit(ch)) {
		buffer_add(ch);
		next_char();
	}
}

/* scan an INTEGER (return 0) or REAL (return 1) */
int scanNUMBER() {
	while (isdigit(ch)) {
		buffer_add(ch);
		next_char();
	}

	if (ch == '.') {
		buffer_add(ch);
		while (isdigit(next_char())) {
			buffer_add(ch);
		}
		return 1; /* real */
	} else {
		return 0; /* integer */
	}
}

void scanSTRING() {
	while (next_char() != '"') {
		if (ch == EOF) {
			yyerror("unexpected end of file");
		}
		buffer_add(ch);
	}
	/* assert(ch == '"') */
}

void scanCHAR() {
	next_char(); /* wirf das Apostroph (') weg */
	if (ch != '\'' && ch != '\n') {
		buffer_add(ch);
	} else {
		yyerror("irregular character read");
	}
	if (next_char() != '\'') {
		yyerror("ending apostrophe expected");
	}
}
