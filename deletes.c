#include "shell.h"

int deleteEntry(map_t *map, const char *key)
{
	list_t *list, *tmp;
	int lmgal;
	entry_t *entry;

	lmgal = hachcode(key);
	list = map->backets[lmgal];
	if (!list)
		return (0);
	entry = list->data;
	if (_strcmp(entry->key, key))
	{
		map->backets[lmgal] = list->next;
		_clear_entry(list->data);
		free(list);
		return (0);
	}
	while (list->next)
	{
		entry = list->next->data;
		if (_strcmp(entry->key, key))
		{
			tmp = list->next;
			list->next = list->next->next;
			_clear_entry(tmp->data);
			free(tmp);
			break;
		}
		list = list->next;
	}
	return (0);
}
