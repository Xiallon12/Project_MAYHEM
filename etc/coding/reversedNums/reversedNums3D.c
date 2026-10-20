#include <stdio.h>

int main() {
	int x, y;
	printf("Enter your 3-digit number: ");
	scanf("%d", &x);
	y = x/100 + (x%10)*99 + x%100;
	printf("Your reversed number is %d.\n", y);
	return 0;
}
