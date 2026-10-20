#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow();
void stack_underflow();

int main(void) {
	make_empty();
	char ch, hr;
	bool enclosed = true;
	int a[] = {0,0};
	printf("Enter your string of parentheses: ");
	while ((ch = getchar()) != '\n') {
		if (ch != ' ')
			push(ch);
	}
	
	while (top > 0) {
		hr = pop();
		switch (hr) {
			case ')': a[0]++; break;
			case '}': a[1]++; break;
			case '(': a[0]--; break;
			case '{': a[1]--; break;
		}
		
		if (a[0] < 0 || a[1] < 0) {
			enclosed = false;
			break;
		}
	}

	if (a[0] > 0 || a[1] > 0) {
		enclosed = false;
	}

	if (enclosed) printf("Enclosed.\n");
	else printf("Not enclosed.\n");
}

void make_empty(void) {
	top = 0;
}

bool is_empty(void) {
	return top == 0;
}

bool is_full(void) {
	return top == STACK_SIZE;
}

void push(char i) {
	if (is_full());
//		stack_overflow();
	else
		contents[top++] = i;
}

char pop(void) {
	if (is_empty());
//		stack_underflow();
	else
		return contents[--top];
}
