#include "lists.h"
/**
 * pop_listint - deltes the head of a linked list.
 * @head: reference pointer to head.
 * Return: head node's data.
*/
int pop_listint(listint_t **head)
{
	listint_t *current = *head;
	int newn;

	if (current == NULL)
	{
		return (0);
	}
	*head = (*head)->next;
	newn = current->n;
	free(current);
	return (newn);
}
