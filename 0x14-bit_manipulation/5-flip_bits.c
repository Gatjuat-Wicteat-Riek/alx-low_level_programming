#include "main.h"

/**
 * flip_bits - counts the number of bits to change in a given number
 * to get from one number to another
 * @num1: first number to be counted
 * @num2: second number to be counted
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	int i, counter = 0;
	unsigned long int current_number;
	unsigned long int num3 = num1 ^ num2;

	for (i = 63; i >= 0; i--)
	{
		current_number = num3 >> i;
		if (current_number & 1)
			counter++;
	}

	return (counter);
}
