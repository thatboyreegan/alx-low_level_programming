#include "lists.h"
/**
 * sum_listint - returns sum of all the data in a alinked list.
 * @head: pointer to the list.
 * Return: sum of all elements
*/
int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum;

	sum = 0;

	if (current == NULL)
	{
		return (0);
	}
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
