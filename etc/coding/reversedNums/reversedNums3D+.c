#include <stdio.h>

int main() {
	int x, y, z, m;
	printf("Enter your 3-digit number: ");
	scanf("%1d%1d%1d", &x, &y, &z);
	m = z*100 + y*10 + x;
	printf("Your reversed number is %d.\n", m);
	return 0;
}
