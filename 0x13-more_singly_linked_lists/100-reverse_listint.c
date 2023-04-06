#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @header: pointer to the first node in the list
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **header)
{
	listint_t *prt = NULL;
	listint_t *next = NULL;

	while (*header)
	{
	next = (*header)->next;
	(*header)->next = prt;
	prt = *header;
	*header = next;
	}

	*header = prt;

	return (*header);
}
