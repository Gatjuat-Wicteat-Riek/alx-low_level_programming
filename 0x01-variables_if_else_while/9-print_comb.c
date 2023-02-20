#include<stdio.h>
/**
 * main - prints all the combination of single digits
 * Return: Always (Success)
 */
int main(void)
{
	int m;

	for (m = 48; m <= 57; m++)
	{
		putchar(m);
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}		
