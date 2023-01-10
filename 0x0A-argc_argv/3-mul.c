#include <stdio.h>
/**
 * main - multiplies two numbers and prints the resuls.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 if succesful, 1 if an error occurs.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		int a, b;

		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d\n", a * b);
		return (0);
	}
}
