#include "search_algos.h"
#include <math.h>

/**
 * min - finds the minimum value of two integers
 * @a: first integer
 * @b: second integer
 * Return: the minimum value between two integers
*/

size_t min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

/**
 * jump_search - finds a value using the jump search algorithm
 * @array: pointer to the first element of the array to search into
 * @size: size of the array to search into
 * @value: the value to search for
 * Return: the first index where the value is found
*/
int jump_search(int *array, size_t size, int value)
{
	size_t block, prev;

	if (!array)
		return (-1);

	prev = block = 0;

	while (array[block - 1] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);

		prev = block;
		block += sqrt(size);
		if (block >= size)
			return (-1);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", prev, block);
	while (array[prev] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
		if ((prev + 1) == min(block, size))
			return (-1);
		prev++;
	}
	if (array[prev] == value)
	{
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
		return (prev);
	}
	else
		return (-1);
}
