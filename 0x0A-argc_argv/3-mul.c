#include <stdio.h>
/**
 * main - multiplies two numbers and prints the resuls.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 if succesful, 1 if an error occurs.
 */
int main(int argc, char *argv[])
{
	if (argv != 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
