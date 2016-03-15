#include <stdio.h>

int main() {
	int fibo=0, pre=1, post=2, sum = 0;

	while (fibo <= 4000000) {
		fibo = post;
		post = pre + fibo;
		pre = fibo;

		if (fibo % 2 == 0)
			sum += fibo;
	}
	printf("%d", sum);

	getch();
	return 0;
}