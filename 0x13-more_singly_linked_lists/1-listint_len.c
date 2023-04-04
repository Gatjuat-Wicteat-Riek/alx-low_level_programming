#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @m: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
	size_t listint_len(const listint_t *m)
	{
	size_t number = 0;

	while (m)
	{
	number++;
	m = m->next;
	}

	return (number);
}
