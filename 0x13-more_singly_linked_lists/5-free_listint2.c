#include "lists.h"
/**
 * free_listint2 - frees a list int and sets head to NULL.
 * @head: reference pointer to the list.
 * Return: None.
*/
void free_listint2(listint_t **head)
{
	listint_t *current = *head;

	while (current != NULL)
	{
	*head = (*head)->next;
	free(current);
	current = *head;
	}
	*head = NULL;
}
