#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned integer
 * @binn: This is the string containing the binary numbers
 * Return: the converted number into binary
 */
unsigned int binary_to_uint(const char *binn)
{
	int k;
	unsigned int dmal_val = 0;

	if (!binn)
		return (0);

	for (k = 0; binn[k]; k++)
	{
		if (binn[k] < '0' || binn[k] > '1')
			return (0);
		dmal_val = 2 * dmal_val + (binn[k] - '0');
	}

	return (dmal_val);
}
