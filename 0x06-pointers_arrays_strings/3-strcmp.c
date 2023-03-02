#include "main.h"
/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to compared.
 * @s2: A pointer to the second string to be compared
 * Return: If str1 < str2. the negative different of the first
 * unmatched characters.
 * if str1 == str2, 0.
 * if str1 > str2, the positive difference of the unmatched character
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
