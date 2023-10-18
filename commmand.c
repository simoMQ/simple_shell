#include "shell.h"

int positionGet(const char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			return (i);
		}
	}
	return (i);
}
