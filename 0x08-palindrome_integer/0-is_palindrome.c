#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - Checks wheter or not given int is palindrome.
 * @n: int
 * Return: 1 if n is palindrome or 0 if not.
 **/

int is_palindrome(unsigned long n)
{

	unsigned tmp, op, trav;

	op = 0;
	tmp = n;

	while (n != 0)
	{
		trav = n % 10;
		op = op * 10 + trav;
		n = n / 10;
	}

	if (tmp == op)
		return (1);
	else
	{
		return (0);
	}
}
