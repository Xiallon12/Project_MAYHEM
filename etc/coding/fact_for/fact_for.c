#include <stdio.h>
#include <stdbool.h>

int fact_for(int x) {
	int result = 1;
	int i = x;
	if (i <= 1)
		goto done;
loop:
	result *= i;
	i--;
	if (i > 1)
		goto loop;
done:
	return result;
}

int main(void) {
	int number;
	scanf("%d", &number);
	int potato = fact_for(number);
	printf("%d\n", potato);
	return 0;
}
