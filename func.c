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
