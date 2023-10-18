#include "shell.h"

int _strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (!*str1 && !*str2)
		return (1);
	return (0);
}
