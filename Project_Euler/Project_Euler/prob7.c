#include<stdio.h>

int isPrimeNumber(int n) {

//	if (n == 2) return 1;
//	else {
		for (int i = 3; i < n; i += 2) {
			if (n%i == 0) return 0;
		}
		return 1;
//	}

}

int main() {
	int n = 1, count = 1;
	
	while (1) {
		n += 2;
		if (isPrimeNumber(n)) count++;
		if (count == 10001) break;
	}

	printf("%d", n);
	getch();
	return 0;
}