#include "shell.h"

int _unsetenv(command_t *command)
{
	int len;

	len = _str2dlen(command->arguments);
	if (len != 2)
	{
		_fprint(2, "%s: Invalid number of arguments\n",
				globalStatus(GET_SHELL_NAME, NULL));
		return (1);
	}
	envimat(DELETE_ENTRY, command->arguments[1], NULL);
	return (0);
}
