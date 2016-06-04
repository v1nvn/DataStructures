#include <stdio.h>

void a(int *p) {
	int a = 56;
	*p = a;
	printf("%d\n", *p);
}
void main() {
	int p;
	a(&p);
	printf("%d\n", p);
}