#include<stdio.h>
/**
 * main - Prints alphabet in lowercase
 * follow by a new line, except q and e
 * Return: Always (Success)
 */
int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		if (n == 101 || n == 113)
		{
			n++;
			continue;
		}
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
