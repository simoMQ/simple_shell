#include "shell.h"

size_t _listlen(const list_t *list)
{
	size_t len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}
