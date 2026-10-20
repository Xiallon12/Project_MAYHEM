#include <stdio.h>

int main() {
	int x, y;
	printf("Enter your 2-digit number: ");
	scanf("%d", &x);
	y = x/10 + (x%10)*10;
	printf("Your reversed number is %d.\n", y);
	return 0;
}
