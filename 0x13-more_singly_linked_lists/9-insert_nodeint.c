#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @header: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **header, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp = *header;

	new = malloc(sizeof(listint_t));
	if (!new || !header)
	return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
	new->next = *header;
	*header = new;
	return (new);
	}

	for (i = 0; temp && i < idx; i++)
	{
	if (i == idx - 1)
	{
	new->next = temp->next;
	temp->next = new;
	return (new);
	}
	else
	temp = temp->next;
	}

	return (NULL);
}
