#ifndef CONTACTS_H
#define CONTACTS_H

struct contact {
	char *contact_name;
	char *contact_number;
};

void contact_add(void);
void contact_view(void);
void contact_delete(void);

#endif
