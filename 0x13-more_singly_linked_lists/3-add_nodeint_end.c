#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a linked list.
 * @head: reference pointer to the head node.
 * @n: data to add to add to the data field.
 * Return: address of the new node.
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current, *temp;

	current = malloc(sizeof(listint_t));

	temp = *head;

	if (current == NULL)
	{
		return (NULL);
	}
	current->n = n;
	current->next = NULL;

	if (temp == NULL)
	{
		*head = current;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = current;
	}
	return (current);
}

