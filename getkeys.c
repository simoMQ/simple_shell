#include "shell.h"

list_t *keyGetGen(const map_t *map)
{
	list_t *list, *itr;
	entry_t *entry;
	int iter;

	list = NULL;
	iter = 0;
	while (iter < BACKET_SIZE)
	{
		itr = map->backets[iter];
		while (itr)
		{
			entry = itr->data;
			addTolist(&list, _strdup(entry->key));
			itr = itr->next;
		}
		iter++;
	}
	return (list);
}
