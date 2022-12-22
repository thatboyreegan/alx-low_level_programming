#include "main.h"
/**
 * print_number - prints an integer.
 * @n: the integer to be printed.
 *
 * Return: void.
 */
void print_number(int n)
{
	unsigned int number;

	number = n;
	if (n < 0)
	{
		_putchar(45);
		number = -n;
	}
	if (number / 10)
	{
		print_number(number / 10);
	}
	_putchar((number % 10) + '0');
}
