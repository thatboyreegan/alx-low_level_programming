#include "search_algos.h"
#include <math.h>
/**
 * jump_list - searches for a value in a sorted list
 *  of integers using the Jump search algorithm.
 * @list: pointer to the head of the list
 * @size: size of the list
 * @value: the value to search for
 * Return: pointer to the first node where the value is found or NULL.
*/


listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t block, i, j;
	listint_t *prev, *current;

	if (!list)
		return (NULL);

	i = 0;
	block = sqrt(size);
	current = list;

	while (current && current->n < value)
	{
		prev = current;
		while (i < block && current)
		{
			current = current->next;
			i++;
		}
		if (current && current->n != value)
			printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
		i = 0;
	}

	if (current)
		j = current->index;
	else
		j = size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", prev->index, j);

	while (prev && prev->index <= j)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			break;
		prev = prev->next;
	}
	if (prev && prev->n == value)
		return (prev);
	return (NULL);
}
