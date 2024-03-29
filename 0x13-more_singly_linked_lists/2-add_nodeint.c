#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @hd: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
	listint_t *add_nodeint(listint_t **hd, const int n)
	{
	listint_t *nw;

	nw = malloc(sizeof(listint_t));
	if (!nw)
	return (NULL);

	nw->n = n;

	nw->next = *hd;
	*hd = nw;

	return (nw);
	}
