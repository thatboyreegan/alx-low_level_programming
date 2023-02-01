#include "lists.h"
/**
 * get_nodeint_at_index - returns a the nth node of a list.
 * @head: pointer to the list.
 * @index: index for node being searched for.
 * Return: NULL if node is not found.
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	listint_t *current = head;

	while (current != NULL)
	{
		count++;
		if (count == (index + 1))
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}
