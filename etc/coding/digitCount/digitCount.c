#include <stdio.h>

int main(void) {
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);
	if (!(number/=10)) printf("1 digit\n");
	else if (!(number/=10)) printf("2 digits\n");
	else if (!(number/=10)) printf("3 digits\n");
	else if (!(number/=10)) printf("4 digits\n");
	else 			printf("more than 4 digits\n");
	return 0;
}
