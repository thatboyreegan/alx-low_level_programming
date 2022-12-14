#include <stdio.h>
#include "main.h"
/**
 * _abs - Computes the absolute value of an integer.
 * @n: int to print.
 * Return: Always 0.
 */
int _abs(int n)
{
	if (n < 0)
	{
		return (n * (-1));
	}
	else if (n == 0)
	{
		return (0);
	}
	else
	{
		return (n);
	}
}
