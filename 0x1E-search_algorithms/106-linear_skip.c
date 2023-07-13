#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the list
 * @value: value to search for
 * Return: pointer to the first node where the value is found or NULL
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i, j;
	skiplist_t *prev, *current;

	if (!list)
		return (NULL);

	current = list->express;
	prev = list;
	i = 0;

	while (current && current->n <= value)
	{
		prev = current;
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
		current = current->express;

		if (!i && current)
			i = current->index - prev->index;
	}

	if (current)
		j = current->index;
	else
		j = current->index + i - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", prev->index, j);

	while (prev && prev != current)
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
