#include <stdio.h>
/**
 * main - program that prints its name followed by a new line
 * if the program is compiled it will print the new name without
 * having to compile it again.
 * @argc: argument count.
 * @argv: argement vector.
 * Return: always 0.
 */
int main(int argc, char *argv[0])
{
	printf("%s\n", argv[0]);
	(void)argc;
	return (0);
}
