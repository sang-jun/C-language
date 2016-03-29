#include <stdio.h>
#include <stdlib.h>

int checkLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;

}

int main() {
	int daysOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year = 1901, day = 1, cnt = 0;

	
	while (year < 2001) {
		if (checkLeapYear(year) == 1) {
			daysOfMonth[1] = 29;
		}
		else {
			daysOfMonth[1] = 28;
		}

		for (int month = 0; month < 12; month++) {
			day += daysOfMonth[month];
			if (day % 7 == 6) {
				cnt++;
			}
		}

		year++;
	}
	printf("%d", cnt);
	system("pause");

	return 0;


}