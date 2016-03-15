#include <stdio.h>

int main() {

	int x, y, n = 100;

	x = (n * (n + 1)) / 2;
	y = (n*(n + 1)*(2 * n + 1)) / 6;

	printf("%d", x*x - y);
	getch();

	return 0;
}