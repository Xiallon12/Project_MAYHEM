#include <stdio.h>

int main(void) {
	int number, numbers[10] =  {0};
	printf("Enter a number: ");
	scanf(" %d", &number);
	for (int i = number; i > 0; i/=10) {
		numbers[i%10] += 1;
	}
	printf("Digits:   0 1 2 3 4 5 6 7 8 9\n");
	printf("Repeated:");
	for (int i = 0; i < 10; i++) {
		printf("%2d", numbers[i]);
	}
	printf("\n");
}
