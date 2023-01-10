#include <stdio.h>
/**
 * main - prints all the passed arguments.
 * @argc: argument count.
 * @argv: vector count.
 * Return: alaways 0.
 */
int main(int argc, char *argv[])
{
int i;

for (i = 0; i < argc; i++)
	printf("%s\n", argv[i]);
return (0);
}
