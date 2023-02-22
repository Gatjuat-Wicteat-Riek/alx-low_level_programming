#include<stdio.h>

/**
 * main - prints the sum of all multiples ofg 3 or 5 up to 1024
 * Return: Always (Success)
 */
int main(void)
{
	int i, b = 0;

	while (i < 1024)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			b += i;
		}
		i++;
	}
	printf("%d\n", b);
	return (0);
}
