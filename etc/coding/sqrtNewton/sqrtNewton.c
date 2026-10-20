#include <stdio.h>
#include <math.h>

int main(void) {
	double x, y, guess=1;
	printf("Welcome to the Square Root Calculator!\n");
	printf("When you enter a number, this calculator will get its square root for ya!\n");
	printf("Enter your number: ");
	scanf("%lf", &x);
	while (fabs(guess - y) > 0.00001*y) {
		y = guess;
		guess = (x/y + y)/2;
	}
	printf("The square root of %g is %g.\n", x, y);
	return 0;
}

