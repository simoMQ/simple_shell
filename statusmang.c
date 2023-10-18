#include "shell.h"

int statusmt(status_actions_t action, int new_status)
{
	static int status;

	if (action == UPDATE_STATUS)
		status = new_status;
	return (status);
}

void *envimat(enviroment_action_t act,
			  const char *key, const char *value)
{
	static map_t *map;

	if (act == INIT_ENV)
		map = initMp();
	else if (act == SET_ENTRY)
		valueSet(map, key, value);
	else if (act == GET_VALUE)
		return (_strdup(_get_value(map, key)));
	else if (act == GET_KEYS)
		return (keyGetGen(map));
	else if (act == CONVERT_INTO_2D)
		return (convert2darry());
	else if (act == CLEAR_ENV)
		clearMp(map);
	else if (act == DELETE_ENTRY)
		deleteEntry(map, key);
	return (NULL);
}

builtins_t bMt(builtin_actions_t act, char *name,
			   int (*function)(command_t *command))
{
	static builtin_t builtins[10];
	static int size;
	int iter;

	if (act == GET_BUILTIN)
	{
		iter = 0;
		while (iter < size)
		{
			if (_strcmp(builtins[iter].name, name))
				return (builtins[iter].function);
			iter++;
		}
	}
	if (act == SET_BUILTIN)
	{
		_copy(builtins[size].name, name, _strlen(name));
		builtins[size].function = function;
		size++;
	}
	return (NULL);
}

void *globalStatus(globals_action_t act, char **s)
{
	static char *line, *shell_name, **array_2d;
	static int line_number;

	if (act == SET_LINE)
		line = *s;
	if (act == SET_SHELL_NAME)
		shell_name = *s;
	if (act == GET_LINE)
		return (line);
	if (act == GET_SHELL_NAME)
		return (shell_name);
	if (act == GET_LINE_NUMBER)
		return (&line_number);
	if (act == INCREMENT_LINE_NUMBER)
		line_number++;
	if (act == SET_2D)
		array_2d = s;
	if (act == GET_2D)
		return (array_2d);
	return (NULL);
}
