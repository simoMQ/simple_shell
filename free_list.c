#include "shell.h"

void free_list(list_t *list, void (*free_content)(void *data))
{
	list_t *current = list;
	list_t *next;

	while (current != NULL)
	{
		next = current->next;
		if (free_content != NULL)
		{
			free_content(current->data);
		}
		free(current);
		current = next;
	}
}
