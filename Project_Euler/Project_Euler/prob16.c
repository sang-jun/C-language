#include <stdio.h>

void mulTwo(int* number) {
	int carry[1000] = { 0, };

	int i = 0;
	int tmp;

	while (number[i] != -1) {
		tmp = number[i] * 2;
		number[i] = tmp % 10;
		carry[i + 1] = tmp / 10;

		i++;

	}

	i = 1;

	while (number[i - 1] != -1) {

		if (number[i] == -1 && carry[i] != 0) number[i] = 0;

		tmp = number[i] + carry[i];
		number[i] = tmp % 10;
		carry[i + 1] += (tmp / 10);


		i++;
	}

	for (i = 0; i < sizeof(carry) / sizeof(int); i++) {
		carry[i] = 0;
	}
}

int main() {
	int number[1000];
	int answer = 0;

	for (int i = 0; i < sizeof(number) / sizeof(int); i++) {
		number[i] = -1;
	}

	number[0] = 2;

	for (int i = 1; i < 1000; i++) {
		mulTwo(number);
	}

	for (int i = 0; i < sizeof(number) / sizeof(int); i++) {
		if (number[i] == -1) break;

		answer += number[i];
	}

	printf("%d", answer);

	getch();
	return 0;

}