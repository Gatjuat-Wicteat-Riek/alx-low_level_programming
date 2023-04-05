#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @header: first node in the linked list
 * @index: index of the node to return
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *header, unsigned int index)
{
	unsigned int bb = 0;
	listint_t *tmp = header;

	while (tmp && bb < index)
	{
	tmp = tmp->next;
	bb++;
	}

	return (tmp ? tmp : NULL);
}
