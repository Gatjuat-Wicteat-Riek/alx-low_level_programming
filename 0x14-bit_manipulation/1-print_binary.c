#include "main.h"

/**
 * print_binary - prints the binary  of a decimal number
 * @bb: number to print in binary
 */
void print_binary(unsigned long int bb)
{
	int i, counter = 0;
	unsigned long int cutt;

	for (i = 63; i >= 0; i--)
	{
		cutt = bb >> i;

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
