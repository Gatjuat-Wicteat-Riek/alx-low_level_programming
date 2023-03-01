#include "main.h"
/**
 * _strncat - Conctanates 2 strings using at most
 * an inputted number of bytes from src.
 * @dest: The string to be appended
 * @src: The string to be appended to dest
 * @n: the number4 of btyed from src to be appended
 * Return: A pointerto the rresulting string
 */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[dest_len++] = src[index];
	return (dest);
}
