#include "shell.h"

char *stlinstttt(const char *line, int start, int end)
{
	char *slice;
	int len, iter;

	if (start < 0)
		start = 0;
	len = _strlen(line);
	if (len < end || end < 0)
		end = len;
	slice = malloc(sizeof(char) * (end - start + 1));
	iter = 0;
	while (start + iter < end)
	{
		slice[iter] = line[start + iter];
		iter++;
	}
	slice[iter] = 0;
	return (slice);
}
