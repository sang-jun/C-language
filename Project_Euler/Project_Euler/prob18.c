#include <stdio.h>

int main() {
	int number[15][15] = { 0, };
	int sum = 0;

	for (int i = 14; i >= 0; i--) {
		
		for (int j = 0; j <= 14-i; j++) {
			scanf_s("%d", &number[i][j]);
		}
	}

	for (int i = 0; i<15; i++)
	{
		for (int j = 0; j <= 14 - i; j++)
		{
			if (number[i][j] <= number[i][j + 1])
				number[i + 1][j] = number[i + 1][j] + number[i][j + 1];
			else
				number[i + 1][j] = number[i + 1][j] + number[i][j];
			
		}
	}

	
	printf("%d\n", number[14][0]);


	getch();
	return 0;

}