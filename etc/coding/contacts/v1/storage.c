#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"
#include "storage.h"

struct phonebook {
	int contacts_number;
	struct contact *storage[MAX_CONTACTS];
};

struct phonebook *phonebook;

void storage_init(void) {
	phonebook = malloc(sizeof(struct phonebook));
	if (phonebook == NULL) {
		printf("Failed to initialize phonebook.\n");
		exit(EXIT_FAILURE);
	}
	phonebook->contacts_number = 0;
	memset(phonebook->storage, 0, sizeof(phonebook->storage));
}

int storage_count(void) {
	return phonebook->contacts_number;
}

storage_function_t storage_insert(struct contact *contact_ptr) {
	int i;

	if (phonebook->contacts_number >= MAX_CONTACTS)
		return STORAGE_FAILURE;

	i = phonebook->contacts_number;
	while (i > 0 && strcmp(phonebook->storage[i-1]->contact_name, contact_ptr->contact_name) > 0) {
		phonebook->storage[i] = phonebook->storage[i-1];
		i--;
	}
	phonebook->storage[i] = contact_ptr;
	phonebook->contacts_number++;

	return STORAGE_SUCCESS;
}

struct contact *storage_find(const char *name) {
	int i;

	for (i = 0; i < phonebook->contacts_number; i++)
		if (strcmp(phonebook->storage[i]->contact_name, name) == 0)
			return phonebook->storage[i];

	return NULL;
}

storage_function_t storage_delete(struct contact *contact_ptr) {
	int i;
	int index = -1;

	for (i = 0; i < phonebook->contacts_number; i++)
		if (phonebook->storage[i] == contact_ptr) {
			index = i;
			break;
		}

	if (index == -1)
		return STORAGE_FAILURE;

	free(contact_ptr->contact_name);
	free(contact_ptr->contact_number);
	free(contact_ptr);

	for (i = index; i < phonebook->contacts_number - 1; i++)
		phonebook->storage[i] = phonebook->storage[i+1];

	phonebook->contacts_number--;
	phonebook->storage[phonebook->contacts_number] = NULL;

	return STORAGE_SUCCESS;
}
