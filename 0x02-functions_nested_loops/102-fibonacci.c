#include<stdio.h>

/**
 * main - Prints the first 52 fibbonaci number
 * Return: Always (Success)
 */
int main(void)
{
	int n = 0;

	long j = 1, k = 2;

	while (n < 50)
	{
	if (n == 0)
	printf("%d", j);
	else if (n == 1)
	printf(", %d", k);
	else
	{
	k += j;
	j = k - j;
	printf(", %d", k);
	}
	++n;
	}
	printf("\n");
	return (0);
}
