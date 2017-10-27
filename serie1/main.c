#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {NORMAL, READING_IDENTIFIER} state_t;

void yyerror(char *msg) {
	fprintf(stderr, "error: %s\n", msg);
	exit(1);
}

char * keywords[] = {"ARRAY", "BEGIN", "CHAR", "CONST", "DO", "ELSE", "ELSIF",
	"END", "FOR", "IF", "INTEGER", "MODULE", "OF", "PROCEDURE", "REAL",
	"REPEAT", "RETURN", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE"};
size_t len_keywords = sizeof(keywords)/sizeof(char *);

char * operators[] = {"OR", "AND", "DIV", "MOD", "NOT"};
size_t len_operators = sizeof(operators)/sizeof(char *);

int is_keyword(char * word) {
	for (size_t i = 0; i < len_keywords; i++) {
		if (strcmp(keywords[i], word) == 0) {
			return 1;
		}
	}
	return 0;
}

int is_operator(char * word) {
	for (size_t i = 0; i < len_operators; i++) {
		if (strcmp(operators[i], word) == 0) {
			return 1;
		}
	}
	return 0;
}

char * yytext;

void fprintf_if_not_special_token(char * word, FILE * stream) {
	if (! (is_keyword(word) || is_operator(word))) {
		fprintf(stream, "%s\n", yytext);
	}
}

void read_and_write_identifiers(FILE * input, FILE * output) {
	/* erstmal machen wir den Buffer für den aktuellen Bezeichner klar */
	size_t bufsize = 1;
	yytext = (char *)calloc(bufsize, sizeof(char));

	int c;
	state_t state = NORMAL;

	/* lese Zeichen für Zeichen ein */
	while ((c = fgetc(input)) != EOF) {
		if (isalpha(c) || (isdigit(c) && state == READING_IDENTIFIER)) {
			/* wir sind auf einen Bezeichner gestoßen! */
			state = READING_IDENTIFIER;

			bufsize += 1;
			yytext = (char *)realloc(yytext, bufsize);
			yytext[bufsize-1] = 0;

			yytext[bufsize-2] = c;
		} else {
			/* Nur wenn wir eben einen Bezeichner eingelesen haben,
			 * geben wir ihn auch aus. Zahlen und so lassen wir weg.
			 */
			state = NORMAL;
			if (bufsize > 1) {
				fprintf_if_not_special_token(yytext, output);
				bufsize = 1;
				yytext = (char *)realloc(yytext, bufsize);
			}
		}
	}

	free(yytext);
}

int main(int argc, char *argv[])
{
	FILE * input = stdin;
	FILE * output = stdout;

	if (argc > 3) {
		yyerror("wrong number of parameters");
	}
	if (argc > 1) {
		input = fopen(argv[1], "r");
		if (input == NULL) {
			yyerror("cannot open file for reading");
		}
	}
	if (argc > 2) {
		output = fopen(argv[2], "w");
		if (output == NULL) {
			yyerror("cannot open file for writing");
		}
	}

	read_and_write_identifiers(input, output);

	fclose(input);
	fclose(output);

	return 0;
}
