#include "shell.h"

void *pop_from_list(list_t **list)
{
	list_t *removed_node = *list;
	void *removed_data = removed_node->data;

	if (!list && *list == NULL)
	{
		return (NULL);
	}

	*list = removed_node->next;
	free(removed_node);

	return (removed_data);
}
