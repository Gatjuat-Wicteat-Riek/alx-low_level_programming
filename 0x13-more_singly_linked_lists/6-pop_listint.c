#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @header: pointer to the first element in the linked list
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **header)
{
	listint_t *tmp;
	int number;

	if (!header || !*header)
	return (0);

	number = (*header)->n;
	tmp = (*header)->next;
	free(*header);
	*header = tmp;

	return (number);
}
