#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @number: number to search with in the range
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int number, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (number >> index) & 1;

	return (bit_value);
}
