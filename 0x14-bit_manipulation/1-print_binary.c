#include "main.h"

/**
 * print_binary - prints the binary  of a decimal number
 * @b: number to be printed in binary format
 */
void print_binary(unsigned long int b)
{
	int k, counter = 0;
	unsigned long int cutt;

	for (k = 63; k >= 0; k--)
	{
		cutt = b >> k;

		if (cutt & 1)
		{
			_putchar('1');
			counter++;
		}
		else if (counter)
			_putchar('0');
	}
	if (!counter)
		_putchar('0');
}
