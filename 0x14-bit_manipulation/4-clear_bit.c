#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @number: pointer to the number to change
 * @indx: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *number, unsigned int indx)
{
	if (indx > 63)
		return (-1);

	*number = (~(1UL << indx) & *number);
	return (1);
}
