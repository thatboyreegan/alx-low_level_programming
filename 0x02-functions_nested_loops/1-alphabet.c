#include "main.h"
/**
 * main - Prints the alphabet in lowercase.
 *
 * Return: Always 0.
 */
void print_alphabet(void)
{
	char alphabet;

	for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
	{
		_putchar(alphabet);
	}
	
	_putchar('\n');
}
