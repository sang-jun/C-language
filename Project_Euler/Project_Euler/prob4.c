#include <stdio.h>
#include <math.h>

int isMirror(int num) {
	int arr_num[6];
	int p = 100000;

	for (int i = 5; i >= 0; i--) {
		arr_num[i] = num / p;
		num = num % p;
		p = p / 10;

	}
	for (int i = 0; i < 6; i++)

		if (arr_num[5] == arr_num[0] && arr_num[4] == arr_num[1] && arr_num[3] == arr_num[2]) return 1;
		else return 0;

}

void main() {
	int xy;
	int biggest = 0;


	for (int x = 999; x >= 100; x--) {
		for (int y = 999; y >= 100; y--) {
			xy = x * y;
			if (isMirror(xy) == 1)
				if (xy > biggest) biggest = xy;
		}
	}
	printf("%d\n", biggest);
	
	getch();
	return 0;

}