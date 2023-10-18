#include "shell.h"

void _handle_sigint(int sig)
{
	(void)sig;
	fflush(stdin);
	if (isatty(STDIN_FILENO))
	{
		_fprint(1, "\n%s> ",
				globalStatus(GET_SHELL_NAME, NULL));
	}
}
