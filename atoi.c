#include "shell.h"

int _atoi(const char *str)
{
	int number;
	int sign;

	sign = 1;
	number = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		number = number * 10 + (*str - 48);
		str++;
	}
	return (number * sign);
}
