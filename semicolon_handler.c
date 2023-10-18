#include "shell.h"

void _execution_handler(command_t *command)
{
	if (access(command->name, F_OK | X_OK) != -1)
		_excute(command);
	else
	{
		_fprint(2, "%s: %d: %s: Permission denied\n",
				(char *)globalStatus(GET_SHELL_NAME, NULL),
				*((int *)globalStatus(GET_LINE_NUMBER, NULL)),
				command->name);
		statusmt(UPDATE_STATUS, 126);
	}
}

int semichr(const char *line)
{
	char **semi_commands, **iterator;
	command_t *command;
	int argument_length;

	iterator = semi_commands = _split(line, ";");
	if (!iterator)
		return (1);
	while (*iterator)
	{
		command = handlcmd(*iterator);
		if (command->type == NOT_FOUND)
		{
			_fprint(2, "%s: %d: %s: not found\n",
					(char *)globalStatus(GET_SHELL_NAME, NULL),
					*((int *)globalStatus(GET_LINE_NUMBER, NULL)),
					command->name);
			statusmt(UPDATE_STATUS, 127);
		}
		else if (command->type == EXTERNAL)
			_execution_handler(command);
		else
		{
			globalStatus(SET_2D, semi_commands);
			statusmt(UPDATE_STATUS,
					 bMt(
						 GET_BUILTIN,
						 command->name, NULL)(command));
		}
		argument_length = _str2dlen(command->arguments);
		envimat(SET_ENTRY, "_",
				command->arguments[argument_length - 1]);
		freeCmd(command);
		iterator++;
	}
	_free_split(&semi_commands);
	return (0);
}
