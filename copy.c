#include "shell.h"

char *_copy(char *dest, const char *src, size_t size)
{
	size_t iter;

	iter = 0;
	while (iter < size)
	{
		dest[iter] = src[iter];
		iter++;
	}
	dest[iter] = 0;
	return (dest);
}
