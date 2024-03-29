#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint - adds a node at the beginning of a linked lists.
 * @head: reference pointer to head.
 * @n: value to add to the data field of the node.
 * Return: address of new element.
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *pointer;

	pointer = malloc(sizeof(listint_t));

	if (pointer == NULL)
	{
	return (NULL);
	}

	pointer->n = n;

	if ((*head) == NULL)
	{
		pointer->next = NULL;
		*head = pointer;
	}
	else
	{
		pointer->next = *head;
		*head = pointer;
	}
return (pointer);
}
