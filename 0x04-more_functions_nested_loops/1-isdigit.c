#include "main.h"
/**
 * _isdigit - Checks for characters that are digits
 * @c: Character to be checked
 * Return: 0 0r 1
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
