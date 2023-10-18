#include "shell.h"

void _clear_entry(void *data)
{
	entry_t *entry;

	entry = data;
	free(entry->key);
	free(entry->value);
	free(data);
}
