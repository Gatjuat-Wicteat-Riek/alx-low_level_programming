#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @header: first node in the linked list
 * Return: resulting sum
 */
int sum_listint(listint_t *header)
{
	int sm = 0;
	listint_t *tmp = header;

	while (tmp)
	{
	sm += tmp->n;
	tmp = tmp->next;
	}

	return (sm);
}
