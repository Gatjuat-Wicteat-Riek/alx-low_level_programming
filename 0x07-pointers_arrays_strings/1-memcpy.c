#include "main.h"
/**
 * _memcpy - a function that copies memory areA
 * @dest: The destination where the file will be keep
 * @src: the source of the file
 * @n: The number of bytes
 * Return: coppies of memory files
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = 0;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
