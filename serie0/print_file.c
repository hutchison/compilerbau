#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Need an input file.\n");
		exit(1);
	}

	FILE * f = fopen(argv[1], "r");

	if (f == NULL) {
		fprintf(stderr, "Can't open file.\n");
		exit(1);
	}

	int c;
	while ((c = fgetc(f)) != EOF) {
		putchar(c);
	}

	fclose(f);

	return 0;
}
