#include <stdio.h>
/**
 * _strlen - Prints a string and its length
 * @str: the string to be printed
 * Return: Always 0
 */
size_t _strlen(const char *str)
{
	size_t lenght = 0;

	while (*str++)
	lenght++;
	return (lenght);
}
