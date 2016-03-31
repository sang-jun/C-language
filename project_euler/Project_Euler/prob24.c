#include <stdio.h>
#include <stdlib.h>

getFactorial(int n) {
	int factorial = n;

	for (int i = n - 1; i > 0; i--) {
		factorial *= i;
	}

	return factorial;
}

int main() {
	int sequence = 0;
	int fixDigit = 0;
	int usedSequence[10] = { 0, };
	int cnt = 0;

	while (fixDigit != 9) {
		sequence += getFactorial(9 - fixDigit);
		if (sequence >= 1000000) {
			sequence -= getFactorial(9 - fixDigit);
			fixDigit++;
			printf("%d\n", cnt);
			cnt = 0;
		}else cnt++;
	}


	system("pause");
	return 0;
}