#include "shell.h"

void pmt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_fprint(1, "%s> ",
				globalStatus(GET_SHELL_NAME, NULL));
	}
}
