#ifndef STORAGE_H
#define STORAGE_H

#define MAX_CONTACTS 100

struct phonebook;
struct contact;

extern struct phonebook *phonebook;

typedef enum storage_functions {
	STORAGE_FAILURE,
	STORAGE_SUCCESS
} storage_function_t;

void storage_init(void);
int storage_count(void);
storage_function_t storage_insert(struct contact *);
storage_function_t storage_delete(struct contact *);
struct contact *storage_find(const char *);

#endif
