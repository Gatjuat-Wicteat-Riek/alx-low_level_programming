#include "main.h"
#include <stdio.h>
/**
 * print_array - Prints n element of an array of an integer
 * @a: The array top be printed
 * @n: The number to be printed
 * Return: void
 */
void print_array(int *a, int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		printf("%d", a[j]);
		if (j != (n - 1))
		{
			printf(", ");
		}
	}
	printf("\n");
}
