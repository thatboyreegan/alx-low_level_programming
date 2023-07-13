#include "search_algos.h"

/**
 * interpolation_search - searches for a value in  an array using
 * interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: size of the array to search into
 * @value: value to search for
 * Return: first index where the value is found or -1 if otherwise
*/
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (!array)
		return (-1);

	low = 0;
	high = size - 1;

	while (low <= high && high < size)
	{
		pos = low + (((double)(high - low) / (array[high]
		 - array[low])) * (value - array[low]));

		if (pos < size)
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		else
			printf("Value checked array[%ld] is out of range\n", pos);

		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;

		if (array[pos] == value)
			return (pos);
	}
	return (-1);
}
