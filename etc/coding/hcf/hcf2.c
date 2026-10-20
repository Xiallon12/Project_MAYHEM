#include <stdio.h>

int euclid(int firstNumber, int secondNumber);

int main(void) {
	int n1, n2, hcf;
	printf("Enter 2 numbers: ");
	scanf("%d %d", &n1, &n2);
	hcf = euclid(n1, n2);
	printf("The hcf is %d.\n", hcf);
	return 0;
}

int euclid(int n1, int n2) {
	int remainder;
	if (n1 == 0)
		return n2;
	else {
		remainder = n2%n1;
		n2 = n1;
		n1 = remainder;
		return euclid(n1, n2);
	}
}
		
