#include "search_algos.h"
/**
 * linear_search - searches for a value in
 * an array using linear search algorithm.
 * @array: pointer the first element of the array
 * @size: size of the array
 * @value: the value to search for
 * Return: the index of the first occurrence of the
 * value or -1 if no such value.
*/


int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
