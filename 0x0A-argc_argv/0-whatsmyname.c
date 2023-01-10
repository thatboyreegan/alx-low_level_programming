#include <stdio.h>
/**
 * main - program that prints its name followed by a new line
 * if the program is compiled it will print the new name without
 * having to compile it again.
 * @argc: argument count.
 * @argv: argement vector.
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[argc - 1]);
	return (0);
}
