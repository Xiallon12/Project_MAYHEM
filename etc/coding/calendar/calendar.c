#include <stdio.h>

int main(void) {
	int numberOfDays, startingDay;
	printf("Enter number of days of the month: ");
	scanf("%d", &numberOfDays);
	printf("Enter starting day (Sat = 1, Fri = 7): ");
	scanf("%d", &startingDay);
	for (int i = 1; i < startingDay; i++) printf("   ");
	for (int i = 1; i <= numberOfDays; i++) {
		printf("%2d ", i);
		if ((i + startingDay -1)%7 == 0 || i == numberOfDays)
			printf("\n");
	}
}

