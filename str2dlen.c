#include "shell.h"

int _str2dlen(char **arr2d)
{
	int len;

	len = 0;
	if (!arr2d)
		return (0);
	while (arr2d[len])
		len++;
	return (len);
}
