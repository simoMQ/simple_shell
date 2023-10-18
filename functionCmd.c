#include "shell.h"

void freeCmd(void *data)
{
	command_t *cmd;

	cmd = data;
	_free_split(&cmd->arguments);
	free(data);
}

char *_looknd(char *command, command_type_t *type)
{

	if (bMt(GET_BUILTIN, command, NULL))
	{
		*type = BUILTINS;
		return (_strdup(command));
	}

	return (pathFromCmd(command));
}

command_t *_inigf(char **tokens)
{
	command_t *command;
	struct stat st;
	char *scommand;

	command = malloc(sizeof(command_t));
	if (!command)
		return (NULL);
	command->type = NOT_FOUND;
	scommand = _looknd(tokens[0], &command->type);
	free(tokens[0]);
	tokens[0] = scommand;
	if (command->type == NOT_FOUND &&
		(tokens[0][0] == '.' || tokens[0][0] == '/') &&
		!stat(tokens[0], &st))
		command->type = EXTERNAL;
	command->arguments = tokens;
	command->name = tokens[0];
	return (command);
}

command_t *handlcmd(const char *line)
{
	char *trline, *nCmd;
	char **tokens[2];
	int iterator;

	trline = trimspace(line);
	tokens[0] = _split(trline, " ");
	free(trline);
	if (!tokens[0])
		return (NULL);
	iterator = 0;
	while (tokens[0][iterator])
	{
		if (tokens[0][iterator][0] == '$')
		{
			nCmd = varEnvm(tokens[0][iterator] + 1);
			free(tokens[0][iterator]);
			if (nCmd)
				tokens[0][iterator] = nCmd;
			else
				tokens[0][iterator] = _strdup("");
		}
		iterator++;
	}
	tokens[1] = _trim_2darray(tokens[0]);
	_free_split(&tokens[0]);
	return (_inigf(tokens[1]));
}
