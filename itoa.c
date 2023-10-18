#include "shell.h"

int _count_number_length(int number)
{
	int len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		len++;
		number *= -1;
	}
	while (number)
	{
		len++;
		number /= 10;
	}
	return (len);
}

char *_itoa(int number)
{
	int len;
	char *str_number;

	len = _count_number_length(number);
	str_number = malloc(sizeof(char) * (len + 1));
	if (!str_number)
		return (NULL);
	str_number[len] = 0;
	if (!number)
	{
		str_number[0] = '0';
		return (str_number);
	}
	if (number < 0)
	{
		str_number[0] = '-';
		number *= -1;
	}
	while (number)
	{
		str_number[--len] = number % 10 + 48;
		number /= 10;
	}
	return (str_number);
}
