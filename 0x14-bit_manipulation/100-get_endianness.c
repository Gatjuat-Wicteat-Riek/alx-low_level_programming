#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for larger number 1 for smaller number
 */
int get_endianness(void)
{
	unsigned int j = 1;
	char *cha = (char *) &j;

	return (*cha);
}
