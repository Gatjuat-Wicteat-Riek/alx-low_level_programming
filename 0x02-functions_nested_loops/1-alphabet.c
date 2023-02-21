#include "main.h"
/**
 * main - prints the alphabet in lowercase
 * Return: Always (Success)
 */
int main(void)
{
	char lc;

	for (lc = 'a'; lc <= 'z'; lc++)
	{
		_putchar(lc);
	}
	_putchar('\n');

	return (0);
}

