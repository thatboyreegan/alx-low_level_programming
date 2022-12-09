#include <stdio.h>
/**
 * main - Prints all the numbers of base16 in lowercase.
 *
 * Return: Always 0.
 */
int main(void)
{
	int num;
	char alphabet;

	for (num = 0; num < 10; num++)
		putchar((num % 10) + '0');

	for (alphabet = 'a'; alphabet <= 'f'; alphabet++)
		putchar(alphabet);

	putchar('\n');

	return (0);
}
