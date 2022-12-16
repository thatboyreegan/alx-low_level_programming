#include "main.h"
/**
 * print_triangle - prints a triangle
 * @size: size of triangle
 * Return: void
 */
void print_triangle(int size)
{
	int i, j, k;

	if (size > 0)
	{
		for (i = size; i > 0; i--)
		{
			for (j = i - 1; j > 0; j--)
				_putchar(' ');
			for (k = size - i + 1; k > 0; k--)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
