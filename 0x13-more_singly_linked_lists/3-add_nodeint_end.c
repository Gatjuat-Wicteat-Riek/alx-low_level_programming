#include "lists.h"
/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @h: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
	listint_t *add_nodeint_end(listint_t **h, const int n)
	{
	listint_t *new;

	listint_t *t = *h;

	new = malloc(sizeof(listint_t));

	if (!new)
	return (NULL);
	new->n = n;
	new->next = NULL;
	if (*h == NULL)
	{
	*h = new;
	return (new);
	}
	while (t->next)
	t = t->next;
	t->next = new;
	return (new);
	}
