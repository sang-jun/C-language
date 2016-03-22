#include <stdio.h>

long long int isPrimeNumber(long long int n) {

	//	if (n == 2) return 1;
	//	else {
	for (long long int i = 3; i*i <= n; i += 2) {
		if (n%i == 0) return 0;
	}
	return 1;
	//	}

}

int main() {
	long long int sum =2 ;

	for (long long int i = 3; i <= 2000000; i += 2) {
		if (isPrimeNumber(i)) sum += i;
	}

	printf("%lld", sum);

	getch();
	return 0;
}