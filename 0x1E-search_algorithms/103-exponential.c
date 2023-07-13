#include "search_algos.h"
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
 * binary_search_t - searches for a value in
 * a sorted array of integers using the binary search algorithm.
 * @array: pointer to the first element of the array
 * @left: pointer to the first element of the array
 * @right: pointer to the lastt element of the array
 * @value: the value to search for
 * Return: index where the value was found or -1 if
 * no such value was found
*/

int binary_search_t(int *array, size_t left, size_t right, int value)
{

	size_t middle = 0;
	size_t index = 0;

	if (!array)
		return (-1);

	while (left <= right)
	{
		middle = (left + right) / 2;
		printf("Searching in array:");
		for (index = left; index < right; index++)
			printf(" %d,", array[index]);
		printf(" %d\n", array[index]);


		if (array[middle] < value)
			left = middle + 1;
		else if (array[middle] > value)
			right = middle - 1;
		else
			return (middle);
	}
	return (-1);
}

/**
 * exponential_search - searches for a value in the array using
 *  exponential search algorithm
 * @array: pointer to the first element of the array
 * @size: size of the array
 * @value: the value to search for
 * Return: first index where the value is found or -1 if otherwise
*/
int exponential_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
		return (-1);

	i = 1;

	while (i < size && array[i] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		i *= 2;
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
	 i / 2, min(i, size - 1));
	return (binary_search_t(array, i / 2, min(i, size - 1), value));
}
