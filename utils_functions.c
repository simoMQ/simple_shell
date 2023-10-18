#include "shell.h"

char **convert2darry(void)
{
	list_t *keys, *iterator;
	size_t len_iter;
	char **array;
	char *tmp[2];

	iterator = keys = envimat(GET_KEYS, NULL, NULL);
	len_iter = _listlen(keys);
	array = malloc(sizeof(char *) * (len_iter + 1));
	if (!array)
	{
		free_list(keys, free);
		return (NULL);
	}
	array[len_iter] = NULL;
	len_iter = 0;
	while (iterator)
	{
		tmp[0] = _strcat(iterator->data, "=");
		tmp[1] = envimat(GET_VALUE,
						 iterator->data,
						 NULL);
		array[len_iter] = _strcat(tmp[0], tmp[1]);
		free(tmp[0]);
		free(tmp[1]);
		iterator = iterator->next;
		len_iter++;
	}
	free_list(keys, free);
	return (array);
}

void feedEnv(char **new_env)
{
	char **entry;

	while (*new_env)
	{
		entry = _split(*new_env, "=");
		envimat(SET_ENTRY, entry[0], entry[1]);
		_free_split(&entry);
		new_env++;
	}
}
