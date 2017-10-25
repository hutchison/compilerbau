#include <stdio.h>

/* Nur Spielerei, weil ich wissen wollte, was rauskommt, wenn man mit
 * Typecasting lustige Sachen anstellt.
 */

int main()
{
	float y = 1.0;
	int * x = (int *) &y;

	printf("%d\n", *x);

	return 0;
}
