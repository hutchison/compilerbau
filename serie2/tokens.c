#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "diagnosis.h"
#include "tokens.h"

extern char* yytext;
extern FILE* yyout;

const char* token_names[] = {
	"KEY_ARRAY", "KEY_BEGIN", "KEY_CHAR", "KEY_CONST", "KEY_DO", "KEY_ELSE",
	"KEY_ELSIF", "KEY_END", "KEY_FOR", "KEY_IF", "KEY_INTEGER",
	"KEY_MODULE", "KEY_OF", "KEY_PROCEDURE", "KEY_REAL", "KEY_REPEAT",
	"KEY_RETURN", "KEY_THEN", "KEY_TO", "KEY_TYPE", "KEY_UNTIL", "KEY_VAR",
	"KEY_WHILE", "ASSIGN", "OR", "AND", "EQ", "NE", "LE", "GE", "LEQ",
	"GEQ", "PLUS", "MINUS", "ASTERISK", "SLASH", "DIV", "MOD", "NOT",
	"SEMICOLON", "PERIOD", "COLON", "COMMA", "LPAREN", "RPAREN", "LBRACK",
	"RBRACK", "RANGE", "IDENT", "INTEGER", "REAL", "CHAR", "STRING"
};

token_list_element* token_list = NULL;
token_list_element* last = NULL;

char * keywords[] = {"ARRAY", "BEGIN", "CHAR", "CONST", "DO", "ELSE", "ELSIF",
	"END", "FOR", "IF", "INTEGER", "MODULE", "OF", "PROCEDURE", "REAL",
	"REPEAT", "RETURN", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE"};
size_t len_keywords = sizeof(keywords)/sizeof(char *);

char * operators[] = {"OR", "AND", "DIV", "MOD", "NOT"};
size_t len_operators = sizeof(operators)/sizeof(char *);

void append(token_t t) {
	token_list_element * elem = (token_list_element *)malloc(sizeof(token_list_element));

	if (elem == NULL) {
		yyerror("could not allocate memory in append()");
	}

	elem->type = t;
	elem->next = NULL;

	if (t == INTEGER) {
		elem->value.integer_constant = atoi(yytext);
	} else if (t == REAL) {
		elem->value.real_constant = atof(yytext);
	} else if (t == CHAR) {
		elem->value.char_constant = yytext[0];
	} else if (t == STRING) {
		elem->value.string_constant = strdup(yytext);
	} else if (t == IDENT) {
		elem->value.string_constant = strdup(yytext);
	}

	if (token_list == NULL) {
		token_list = elem;
		last = elem;
	} else {
		last->next = elem;
		last = elem;
	}
}

void output_token_list() {
	token_list_element * elem;

	for (elem = token_list; elem != NULL; elem = elem->next) {
		if (elem->type == INTEGER) {
			fprintf(yyout, "<INTEGER, %d>", elem->value.integer_constant);
		} else if (elem->type == REAL) {
			fprintf(yyout, "<REAL, %f>", elem->value.real_constant);
		} else if (elem->type == STRING) {
			fprintf(yyout, "<STRING, %s>", elem->value.string_constant);
		} else if (elem->type == CHAR) {
			fprintf(yyout, "<CHAR, %c>", elem->value.char_constant);
		} else if (elem->type == IDENT) {
			fprintf(yyout, "<IDENT, %s>", elem->value.string_constant);
		} else {
			fprintf(yyout, "<%s>", token_names[elem->type]);
		}
		fprintf(yyout, " ");
	}
	fprintf(yyout, "\n");
}

void delete_token_list() {
	if (token_list == NULL) {
		return;
	} else {
		token_list_element * elem = token_list;
		token_list_element * next_elem = elem->next;

		while (next_elem != NULL) {
			free(elem);
			elem = next_elem;
			next_elem = next_elem->next;
		}

		free(elem);
	}
}

int iskeyword(char * word) {
	for (size_t i = 0; i < len_keywords; i++) {
		if (strcmp(keywords[i], word) == 0) {
			return i;
		}
	}

	if (strcmp(yytext, "OR") == 0) {
		return OR;
	}
	if (strcmp(yytext, "AND") == 0) {
		return AND;
	}
	if (strcmp(yytext, "DIV") == 0) {
		return DIV;
	}
	if (strcmp(yytext, "MOD") == 0) {
		return MOD;
	}
	if (strcmp(yytext, "NOT") == 0) {
		return NOT;
	}

	return -1;
}
