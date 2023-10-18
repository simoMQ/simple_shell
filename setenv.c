#include "shell.h"

int _setenv(command_t *command)
{
	int len;

	len = _str2dlen(command->arguments + 1);
	if (len != 2)
	{
		_fprint(2, "%s: Invalid number of arguments\n",
				globalStatus(GET_SHELL_NAME, NULL));
		return (1);
	}
	envimat(
		SET_ENTRY,
		command->arguments[1],
		command->arguments[2]);
	return (0);
}
