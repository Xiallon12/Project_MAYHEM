#include <stdio.h>

int main(void) {
	int m, n, remainder;
	printf("Enter two numbers: ");
	scanf("%d %d", &m, &n);
	while (n != 0) {
		remainder = m%n;
		m = n;
		n = remainder;
	}
	printf("The HCF is: %d\n", m);
	return 0;
}
