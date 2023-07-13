#include "search_algos.h"
/**
 * binary_search - searches for a value in
 * a sorted array of integers using the binary search algorithm.
 * @array: pointer to the first element of the array
 * @size: size of the array
 * @value: the value to search for
 * Return: index where the value was found or -1 if
 * no such value was found
*/

int binary_search(int *array, size_t size, int value)
{

	size_t left = 0;
	size_t middle = 0;
	size_t right = size - 1;
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
