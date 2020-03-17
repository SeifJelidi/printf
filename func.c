#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"
#include <unistd.h>
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
	{
		write(1, "(null)", 6);
		return (6);
	}

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

/**
 * case_binary - returns number of digits after converting to binary
 * Description: returns number of digits after converting to binary
 * @n: decimal number int
 * Return: number of digits after converting to binary
 */

int case_binary(unsigned int n)
{
	int b[32];
	int i = 0, s = 0, j;

	while (n > 0)
	{
		b[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (j = i - 1 ; j >= 0 ; j--)
	{
		_putchar(b[j] + '0');
		s++;
	}
	return (s);
}

/**
 * case_r - returns length of string and print it  in reverse
 * Description: returns length of string and print it in reverse
 * @ch: character string
 * Return: length of string
 */

int case_r(char *ch)
{
	int i = 0, s = 0;

	if (ch == NULL)
		ch = "(nil)";
	while (ch[i] != '\0')
		i++;
	i--;
	for (; i >= 0; i--)
	{
		_putchar(ch[i]);
		s++;
	}
	return (s);
}

/**
 * case_R - encodes rot13
 * Description: encodes rot13
 * @ch: character string
 * Return: length of string encoded
 */

int case_R(char *ch)
{
	int i, j, s = 0;
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; *(ch + i); i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (a[j] == *(ch + i))
			{
				*(ch + i) = b[j];
				break;
			}
		}
	}
	for (i = 0 ; ch[i] != '\0' ; i++)
	{
		_putchar(ch[i]);
		s++;
	}
	return (s);
}
