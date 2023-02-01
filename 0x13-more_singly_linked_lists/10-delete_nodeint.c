#include "lists.h"
/**
 * delete_nodeint_at_index - deletes a node at the given index.
 * @head: reference pointer to head.
 * @index: given index.
 * Return: 1 for succuss and -1 for failure.
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head, *temp;
	unsigned int count;

	count = 1;
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (current != NULL)
	{
		if (count == index)
		{
			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (1);
		}
		current = current->next;
		count++;
	}
	return (-1);
}
