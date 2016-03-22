#include<stdio.h>

int main() {
	int a, b, c;

	for (c = 998; c > 333; c--) {
		for (b = 1000-c-1; b > 0; b--) {
			a = 1000 - b - c;
			if (c*c == a*a + b*b) {
				printf("a = %d, b = %d, c = %d\n", a, b, c);
				printf("a * b * c = %d", a*b*c);
				break;
			}
		}
	}

	getch();
	return 0;
}