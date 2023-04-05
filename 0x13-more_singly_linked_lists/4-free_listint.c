#include "lists.h"

/**
 * free_listint - frees a linked list
 * @hdd: listint_t list to be freed
 */
void free_listint(listint_t *hdd)
{
	listint_t *tmp;

	while (hdd)
	{
	tmp = hdd->next;
	free(hdd);
	hdd = tmp;
	}
}
