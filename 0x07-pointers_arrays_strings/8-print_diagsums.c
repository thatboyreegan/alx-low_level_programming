#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix.
 * @a: square matrix for printing the sum of diagonals.
 * @size: size of the matrix.
 */
void print_diagsums(int *a, int size)
{
	int i;

	unsigned int x, z;

	x = 0;
	z = 0;

	for (i = 0; i < size; i++)
	{
		x += a[(size * i) + i];
		z += a[(size * (i + 1)) - (i + 1)];
	}
	printf("%d, %d\n", x, z);
}
