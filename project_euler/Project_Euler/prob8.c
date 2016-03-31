#include <stdio.h>
#include <stdlib.h>

long long int mulNumber(int x, int y, char* number) {
	long long int n = 1;

	for (int i = x; i < y; i++) {
		n *= number[i] - '0';
	}

	return n;
}

int main() {
	char number[1000];
	long long int max = 0, temp;

	for (int i = 0; i < 1000; i++) {
		scanf_s("%c", &number[i]);
	}

	for (int i = 0; i < 1000 - 13; i++) {
	 	temp = mulNumber(i, i + 13, number);
		printf("%d >> %d\n", i, temp);
		if (max < temp) max = temp;
	}

	printf("%lld\n", max);

	system("pause");
	return 0;
}