#include <stdio.h>

/*
long long int gcd(long long int x,long long int y) {
long long int temp;
if (x < y) {
temp = x;
x = y;
y = temp;
}

if (y == 0) return x;
else return gcd(y, x%y);
}

long long int lcm(long long int x, long long int y) {
return x*y / gcd(x, y);
}

void main() {
long long int i, j = 2;
for (i = 3; i <= 20; i++) {
j = lcm(j, i);
}

printf("%lld\n", j);

scanf_s("%d", &i);


}
*/


int main() {
	int i;
	

	
	for (i = 20;; i += 20) {
		for (int j = 2; j <= 19; j++) {
			if (i%j != 0) break;
			if (j == 19) {
				goto end;
			}
		}
	}
	end:

	printf("%d\n", i);
	getch();
	return 0;
}
