#include "main.h"
/**
 * _memset - fill a block of  memory with a specific value
 * @s: starting addres of a memory
 * @b: the desired value
 * @n: number of bytes
 * Return: number of bytes to be changed
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
