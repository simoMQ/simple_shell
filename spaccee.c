#include "shell.h"

size_t _get_length_without_space_dup(const char *line, size_t end)
{
	size_t start, len;
	int is_space;

	start = 0;
	is_space = 0;
	len = 0;
	while (start < end)
	{
		if ((line[start] == ' ' ||
			 line[start] == '\t') &&
			!is_space)
		{
			len++;
			is_space = 1;
		}
		else if (line[start] != ' ' &&
				 line[start] != '\t')
		{
			is_space = 0;
			len++;
		}
		start++;
	}
	return (len);
}

char *_get_newline_without_space_dup(const char *line, size_t end)
{
	size_t start, index;
	int is_space;
	char *newline;

	start = 0;
	is_space = 0;
	index = 0;
	newline = malloc(sizeof(char) *
					 (_get_length_without_space_dup(line, end + 1) + 1));
	if (!newline)
		return (NULL);
	while (start <= end)
	{
		if ((line[start] == ' ' ||
			 line[start] == '\t') &&
			!is_space)
		{
			newline[index] = ' ';
			index++;
			is_space = 1;
		}
		else if (line[start] != ' ' &&
				 line[start] != '\t')
		{
			is_space = 0;
			newline[index] = line[start];
			index++;
		}
		start++;
	}
	newline[index] = 0;
	return (newline);
}

char *trimspace(const char *line)
{
	size_t left, right;
	char *s;

	left = 0;
	right = _strlen(line);
	if (!right)
	{
		s = malloc(sizeof(char));
		*s = 0;
		return (s);
	}
	right -= 1;
	while (line[left] == ' ' || line[left] == '\t')
		left++;
	while (right > left &&
		   (line[right] == ' ' || line[right] == '\t'))
		right--;
	if (left > right)
	{
		s = malloc(sizeof(char));
		*s = 0;
		return (s);
	}
	return (_get_newline_without_space_dup(line + left, right - left));
}
