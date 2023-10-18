#include "shell.h"

int _env(command_t *command)
{
	char **iterator;

	(void)command;

	iterator = __environ;
	if (!iterator)
		return (1);
	while (*iterator)
	{
		_fprint(1, "%s\n", *iterator);
		iterator++;
	}
	return (0);
}
