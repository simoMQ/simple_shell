#include "shell.h"

int cdHelps(const char *key)
{
	char *s, buffer[200];

	getcwd(buffer, 200);
	s = envimat(GET_VALUE, key, NULL);
	if (chdir(s) == -1)
	{
		free(s);
		return (errno);
	}
	envimat(SET_ENTRY, "OLDPWD", buffer);
	free(s);
	return (0);
}

int cdHelps2(const char *path)
{
	char buffer[200];

	getcwd(buffer, 200);
	if (chdir(path) == -1)
	{
		perror(globalStatus(GET_SHELL_NAME, NULL));
		return (errno);
	}
	envimat(SET_ENTRY, "OLDPWD", buffer);
	return (0);
}

int _cd(command_t *cmd)
{
	int len;

	len = _str2dlen(cmd->arguments + 1);

	if (len >= 1)
	{
		if (_strcmp("-", cmd->arguments[1]))
			return (cdHelps("OLDPWD"));
		else if (_strcmp("~", cmd->arguments[1]))
			return (cdHelps("HOME"));
		else
			return (cdHelps2(cmd->arguments[1]));
	}
	else if (!len)
		return (cdHelps("HOME"));
	return (0);
}
