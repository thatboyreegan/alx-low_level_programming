#include "lists.c"
/**
 * add_nodeint_end - adds a new node at the end of a linked list.
 * @head: reference pointer to the head node.
 * @n: data to add to add to the data field.
 * Return: address of the new node.
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = *head, *current;

	current = malloc(sizeof(listint_t));

	if (current == NULL)
	{
		return (NULL);
	}
	current->n = n;
	current->next = NULL;

	while (new != NULL)
	{
		new = new->next;
	}
	new->next = current;
	return (current);
}
