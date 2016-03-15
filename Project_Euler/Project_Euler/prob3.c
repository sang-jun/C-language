#include<stdio.h>

long getPrime(long num) {
	long i, j;
	for (i = num + 1;; i++) {
		for (j = 2; j <= i; j++) {
			if (i == j) return i;
			if (i%j == 0) break;
		}
	}

}

int main() {
	long long number = 600851475143;
	long num = 2;
	long temp;

	printf("%lld\n", number);
	while (number != 1) {

		if (number%num == 0) {
			number = number / num; printf("%ld\n", num);
		}
		else {

			temp = num;
			num = getPrime(temp);
		}

	}

	printf("%ld\n", num);

	getch();
	return 0;
}