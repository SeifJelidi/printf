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
 * case_int - returns number of digits
 * Description: returns number of digits
 * @n: number int
 * Return: number of digits
 */

int case_int(int n)
{
	int n1, n2, c = 0, i = 0;
	long int l = 1;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		n1 = n * (-1);
	}
	else
		n1 = n;
	n2 = n1;
	while (n1 != 0)
	{
		n1 /= 10;
		l *= 10;
		c++;
	}
	l /= 10;
	i = c;
	while (c != 0)
	{
		_putchar((n2 / l) + '0');
		n2 %= l;
		l /= 10;
		c--;
	}
	if (n < 0)
		i++;
	return (i);
}
