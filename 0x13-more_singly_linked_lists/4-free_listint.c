#include "lists.h"
/**
 * free_listint - frees a list.
 * @head: pointer to head.
 * Return: None.
*/
void free_listint(listint_t *head)
{
	listint_t *current = head;

	while (current != NULL)
	{
	head = head->next;
	free(current);
	current = head;
	}
}
