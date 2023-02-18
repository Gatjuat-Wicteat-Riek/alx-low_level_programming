#include<stdio.h>
/**
 * main - prints all the combination of single digits
 * Return: Always (Success)
 */
int main(void)
{
	int m;

	for (m = 48; m < 58; m++)
		putchar(m);
		if (m != 57)
		{
			putchar(',');
			putchar(' ');
		}
	putchar('\n');
	return (0);
}
