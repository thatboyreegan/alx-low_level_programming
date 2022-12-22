#include "main.h"
/**
 * reverse_array - reverses an array.
 * @a: pointer to array.
 * @n: number of elements in the array.
 *
 * Return: void.
 */
void reverse_array(int *a, int n)
{
	int i, j;

	n = n - 1;
	j = 0;
	while (j <= n)
	{
		i = a[i];
		a[i++] = a[n];
		a[n--] = i;
	}
}
