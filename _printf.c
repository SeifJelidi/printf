#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * _printf - produces output according to a format
 * Description: produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, s = 0;

	va_start(list, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0 ; format[i] != '\0' ; i++)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					_putchar(va_arg(list, int));
					s++;
					break;
				case 's':
					s += case_string(va_arg(list, char *));
					break;
				case 'i':
				case 'd':
					s += case_int(va_arg(list, int));
					break;
				default:
					_putchar(format[i]);
					_putchar(format[i + 1]);
					s++;
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i++, s++;
		}
		else
		{
			_putchar(format[i]);
			s++;
		}
	}
	va_end(list);
	return (s);
}
