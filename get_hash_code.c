#include "shell.h"

int hachcode(const char *key)
{
	int hash = 0;
	int i;

	for (i = 0; key[i] != '\0'; i++)
	{
		hash += key[i];
	}

	return (hash % BACKET_SIZE);
}
