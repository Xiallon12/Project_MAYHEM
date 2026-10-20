#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"
#include "storage.h"

#define MAX_LEN 50

static char *read_string(void);

void contact_add(void) {
	if (storage_count() >= MAX_CONTACTS) {
		printf("\nCan't add more contacts.\n\n");
		return;
	}
	
	struct contact *contact_ptr = malloc(sizeof(struct contact));
	if (contact_ptr == NULL) {
		printf("\nFailed to malloc the pointer.\n\n");
		return;
	}

	printf("Enter contact name: ");
	contact_ptr->contact_name = read_string();
	printf("Enter contact number: ");
	contact_ptr->contact_number = read_string();
	if (contact_ptr->contact_name == NULL || contact_ptr->contact_number == NULL) {
		free(contact_ptr->contact_name);
		free(contact_ptr->contact_number);
		free(contact_ptr);
		printf("\nFailed to add name or number.\n\n");
		return;
	}

	if (strlen(contact_ptr->contact_name) == 0 || strlen(contact_ptr->contact_number) == 0) {
		printf("\nYou can't leave it empty, moron.\n");
		free(contact_ptr->contact_name);
		free(contact_ptr->contact_number);
		free(contact_ptr);
		printf("Failed to insert contact.\n\n");
		return;
	}

	if (storage_insert(contact_ptr) == STORAGE_FAILURE) {
		free(contact_ptr->contact_name);
		free(contact_ptr->contact_number);
		free(contact_ptr);
		printf("\nFailed to insert contact.\n\n");
		return;
	}

	printf("\nContact added successfully.\n\n");
}

void contact_view(void) {
	struct contact *contact_ptr;
	char *finder_name;
	printf("Please enter the contact's name (enter 0 to exit): ");
	for (;;) {
		finder_name = read_string();
		if (finder_name == NULL) {
			printf("\nNo memory.\n\n");
			return;
		}
		if (strcmp(finder_name, "0") == 0) {
			free(finder_name);
			return;
		}

		if ((contact_ptr = storage_find(finder_name)) == NULL) {
			printf("\nCouldn't find name, try again (enter 0 to exit): ");
			free(finder_name);
			continue;
		}
		else {
			free(finder_name);
			break;
		}
	}

	printf("\nContact Name: %s\n", contact_ptr->contact_name);
	printf("Contact Number: %s\n\n", contact_ptr->contact_number);
	return;

}

void contact_delete(void) {
	struct contact *contact_ptr;
	char *finder_name;

	if (storage_count() == 0) {
		printf("\nAdd something first, bozo.\n\n");
		return;
	}	
	
	printf("Please enter the contact's name (enter 0 to exit): ");
	for (;;) {
		finder_name = read_string();
		if (finder_name == NULL) {
			printf("No memory.\n\n");
			return;
		}
		else if (strcmp(finder_name, "0") == 0) {
			free(finder_name);
			return;
		}

		if ((contact_ptr = storage_find(finder_name)) == NULL) {
			printf("\nCouldn't find name, try again (enter 0 to exit): ");
			free(finder_name);
			continue;
		}
		break;
	}
	if (storage_delete(contact_ptr) == STORAGE_FAILURE)
		printf("\nDeletion failed.\n\n");
	else
		printf("\nContact removed successfully.\n\n");
	free(finder_name);
}




static char *read_string(void) {
	char buffer[MAX_LEN+1];
	char *p = buffer;
	int ch;
	
	while ((ch = getchar()) != '\n' && ch != EOF) 
		if (p < buffer + MAX_LEN)
			*(p++) = ch;
	*p = '\0';
	size_t len = p - buffer;

	char *string = malloc(len+1);
	if (string != NULL)
		strcpy(string, buffer);
	
	return string;
}


