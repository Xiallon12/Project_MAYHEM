#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"
#include "storage.h"

char menu_prompt(char *valid_inputs);

int main(void) {
	char input;

	storage_init();

	printf("=====================================\n"
	       "Welcome to the Contacts Manager V1.0!\n");
	for (;;) {
		printf("Choose what you want to do:\n"
		       	"1- Add a contact.\n"
		       	"2- View a contact.\n"
			"3- Remove a contact.\n"
			"0- Exit.\n"
	       		"Enter a number from 0-3: ");
		input = menu_prompt("0123");

		switch (input) {
			case '0': exit(EXIT_SUCCESS); break;
			case '1': contact_add(); break;
			case '2': contact_view(); break;
			case '3': contact_delete(); break;
		}
	}
	return 0;
}


// prompts for user input until the user enters an expected value
char menu_prompt(char *choices) {
	char input;
	for (;;) {
		scanf(" %c", &input);
		while (getchar() != '\n')
			;
		if (strchr(choices, input) != NULL)
			return input;
		else
			printf("Invalid Input. Try Again: ");
		}
}

