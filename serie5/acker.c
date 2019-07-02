#include <stdio.h>
/* compiled from module "ackermann" */ 

/* global declarations */
int x;
int a;
int b;

int acker(int x, int y) {
/* acker's local declarations */

/* code */
if ((x == 0)) {
return (y + 1);
} else if ((y == 0)) {
return acker((x - 1), 1);
} else {
return acker((x - 1), acker(x, (y - 1)));
};
}


/* main program */
int main() {
a = 3;
b = 2;
x = acker(a, b);
printf("x = %d\n" ,x);
}
