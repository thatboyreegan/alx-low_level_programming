#include "lists.h"
/**
 * find_listint_loop - finds loop in a linked list.
 * @head: head of list.
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current, *new;

	current = head;
	new = head;

	while (head && current && current->next)
	{
		head = head->next;
		current = current->next->next;

		if (head == current)
		{
			head = new;
			new = current;

			while (1)
			{
				current = new;

				while (current->next != head && current->next != new)
				{
					current = currnet->next;
				}
				if (current->next == head)
					break;

				head = head->next;
			}
			return (current->next);
		}
	}
	return (NULL);
}
