#include<stdio.h>
/**
 * main - Prints alphabet in lowercase
 * follow by a new line, except q and e
 * Return: Always (Success)
 */
int main(void)
{
	char la;

	for (la = 'a'; la <= 'z'; la++)
	{
		if (la != 'e' && 'q')
			putchar(la);
	}
	putchar('\n');
	return (0);
}
