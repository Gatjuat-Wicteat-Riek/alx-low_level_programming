#include<stdio.h>
/**
 * main - prints alphabet in a reverse order
 * Return: Always (Success)
 */
int main(void)
{
	char lr;

	for (lr = 'z'; lr >= 'a'; lr--)
	{
		putchar(lr);
	}
	putchar('\n');
	return (0);
}
