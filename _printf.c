#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * case_string - returns length of a string
 * Description: returns length of a string
 * @ch: character string
 * Return: length of a string
 */

int case_string(char *ch)
{
	int i;
	int s = 0;

	if (ch == NULL)
		ch = "(nil)";
	for (i = 0 ; ch[i] != '\0' ; i++)
	{
		_putchar(ch[i]);
		s++;
	}
	return (s);
}

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
	if (format == NULL)
		return (-1);
	for (i = 0 ; format[i] != '\0' && format ; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (; format[i] == ' ' ; i++);
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(list, int));
					s++;
					break;
				case 's':
					s += case_string(va_arg(list, char *));
					break;
				case '%':
					_putchar('%');
					s++;
				case '\0':
					return (-1);
			}
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
