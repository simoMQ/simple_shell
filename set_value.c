#include "shell.h"

int valueSet(map_t *map, const char *key, const char *value)
{
	int backet_index;
	list_t *iterator;
	entry_t *entry;

	backet_index = hachcode(key);
	iterator = map->backets[backet_index];
	while (iterator)
	{
		entry = iterator->data;
		if (_strcmp(entry->key, key))
		{
			free(entry->value);
			entry->value = _strdup(value);
			return (1);
		}
		iterator = iterator->next;
	}
	entry = malloc(sizeof(entry_t));
	if (!entry)
		return (0);
	entry->key = _strdup(key);
	entry->value = _strdup(value);
	addTolist(&map->backets[backet_index], entry);
	return (1);
}
