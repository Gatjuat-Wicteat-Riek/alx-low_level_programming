#include<stdio.h>
/**
 * main - Prints number in base 16
 * Return: Always (Success)
 */
int main(void)
{
	int num;
	char lb;

	for (num = 0; num < 10; num++)
	{
		putchar((num % 10) + '0');
	}
	for (lb = 'a'; lb <= 'f'; lb++)
		putchar(lb);
	putchar('\n')
	return (0);
}
