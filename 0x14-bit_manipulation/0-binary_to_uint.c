#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned integer
 * @binn: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *binn)
{
	int i;
	unsigned int dmal_val = 0;

	if (!binn)
		return (0);

	for (i = 0; binn[i]; i++)
	{
		if (binn[i] < '0' || binn[i] > '1')
			return (0);
		dmal_val = 2 * dmal_val + (binn[i] - '0');
	}

	return (dmal_val);
}
