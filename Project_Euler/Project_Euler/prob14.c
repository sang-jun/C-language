#include <stdio.h>


long long int getHailstoneSequenceCount(long long int n) {
	if (n == 1) {
		return 1;
	}
	else {
		if (n % 2 == 0)
			n = n / 2;		
		else
			n = (3 * n) + 1;

		return getHailstoneSequenceCount(n) + 1;
	}
}

int main() {
	long long int maxCount = 0;
	long long int count = 0;
	long long int answer = 0;

	for (long long int i = 1; i <=1000000; i++) {
		count = getHailstoneSequenceCount(i);

		if (maxCount < count) {
			maxCount = count;
			answer = i;
		}
	}

	printf("%lld ___ %lld",maxCount, answer);

	getch();
	return 0;
}

/*
long long int getHailstoneSequence(long long int n) {
	if (n % 2 == 0) {
		n = n / 2;
	}
	else {
		n = (3 * n) + 1;
	}

	return n;
}
int main() {
	long long int maxCnt = 0;
	long long int answer;

	for (long long int i = 113383; i <= 1000000; i++) {

		long long int hailstoneSeq = i;
		long long int cnt=0;
		

		while (1) {
			hailstoneSeq = getHailstoneSequence(hailstoneSeq);
			cnt++;
			
			if (hailstoneSeq == 1) {
				break;
			}
		}
		if (cnt > maxCnt) { 
			maxCnt = cnt;
			answer = i;
		}
	}
	printf("%lld ___ %lld", maxCnt, answer);

	getch();
	return 0;
}
*/