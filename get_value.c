#include "shell.h"

char *_get_value(const map_t *map, const char *key)
{
	int backet_index;
	list_t *backet;
	entry_t *entry;

	backet_index = hachcode(key);
	backet = map->backets[backet_index];
	while (backet)
	{
		entry = backet->data;
		if (_strcmp(entry->key, key))
			return (entry->value);
		backet = backet->next;
	}
	return (NULL);
}
