#include "shell.h"

int _fput_number_helper(int fd, int number)
{
	int ret;
	char c;

	if (number == 0)
		return (0);
	ret = _fput_number_helper(fd, number / 10);
	c = number % 10 + 48;
	write(fd, &c, 1);
	return (1 + ret);
}

int _fput_number(int fd, int number)
{
	int printed;

	printed = 0;
	if (!number)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (number < 0)
	{
		write(fd, "-", 1);
		printed = 1;
		number *= -1;
	}
	return (printed + _fput_number_helper(fd, number));
}

int _fputs(int fd, const char *s)
{
	return (write(fd, s, _strlen(s)));
}

int _fprint(int fd, const char *format, ...)
{
	va_list ap;
	int index, printed;
	int is_percent;

	va_start(ap, format);
	is_percent = 0;
	index = 0;
	printed = 0;
	while (format[index])
	{
		if (format[index] == '%')
			is_percent = 1;
		else
		{
			if (is_percent)
			{
				if (format[index] == 'd')
					printed += _fput_number(fd, va_arg(ap, int));
				else if (format[index] == 's')
					printed += _fputs(fd, va_arg(ap, char *));
				else
					printed += write(fd, &format[index - 1], 2);
			}
			else
				printed += write(fd, format + index, 1);
			is_percent = 0;
		}
		index++;
	}
	va_end(ap);
	return (printed);
}
