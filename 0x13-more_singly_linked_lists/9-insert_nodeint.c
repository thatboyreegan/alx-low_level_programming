#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node at a given index.
 * @head: reference pointer to head.
 * @idx: index of the node.
 * @n: data n.
 * Return: address of the new node.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *current, *temp;
	unsigned int count;

	new = malloc(sizeof(listint_t));



	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	current = *head;

	count = 0;

	while (current != NULL)
	{
		count++;
		if (count == idx)
		{
			temp = current->next;
			current->next = new;
			new->next = temp;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}
