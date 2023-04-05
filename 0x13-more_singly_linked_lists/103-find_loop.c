#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @hdd: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
	listint_t *find_listint_loop(listint_t *hdd)
	{
	listint_t *slw = hdd;

	listint_t *fst = hdd;

	if (!hdd)
	return (NULL);
	while (slw && fst && fst->next)
	{
	fst = fst->next->next;
	slow = slow->next;
	if (fst == slw)
	{
	slw = hdd;
	while (slw != fst)
	{
	slw = slw->next;
	fst = fst->next;
	}
	return (fst);
	}
	}
	return (NULL);
	}
