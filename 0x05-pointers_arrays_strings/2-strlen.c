#include "main.h"
/**
 * _strlen - Prints a string and its length
 * @str: the string to be printed
 * Return: Always 0
 */
int _strlen(char *str)
{
	for (; *str != '\0'; str++)
	{
		_putchar(*str);
	}
	_putchar('\n');

	return (0);
}
