#include <stdio.h>
/**
 * main - prints number of arguments passed to the program.
 * @argc: argument count
 * @argv: argmentn vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argv[0])
		printf("%d\n", argc - 1);
	return (0);
}
