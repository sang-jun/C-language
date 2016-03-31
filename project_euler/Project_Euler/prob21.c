#include <stdio.h>
#include <stdlib.h>
int d[10001] = { 0, };

int getD(int n) {
	if (d[n] != 0) { 
		return d[n];
	}
	else {
		int sum = 0;

		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
			}
		}
		return d[n] = sum;
	}
}

int main() {
//	int temp, answer = 0;
//
//	for (int i = 1; i <= 10000; i++) {
//		temp = getD(i);
//		if ((temp <= 10000) && (temp != i) && (temp == getD(temp))) {
//			answer += temp;
//			printf("%d\n", temp);
//			
//		}
//	}
//
//	printf("%d\n", answer);
//	system("pause");
//
//	return 0;
}