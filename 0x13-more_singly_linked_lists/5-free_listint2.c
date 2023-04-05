#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @hdd: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **hdd)
{
	listint_t *tmp;

	if (hdd == NULL)
	return;

	while (*hdd)
	{
	tmp = (*hdd)->next;
	free(*hdd);
	*hdd = tmp;
	}

	*hdd = NULL;
}
