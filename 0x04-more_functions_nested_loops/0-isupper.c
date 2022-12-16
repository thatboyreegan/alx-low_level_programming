#include "main.h"

/**
 * _isupper - checks for uppercase character
 * @c: input
 * Return: 1 if uppercase 0 if otherwise
 */
int _isupper(int c)
{
	if ((c <= 'Z') && (c >= 'A'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
