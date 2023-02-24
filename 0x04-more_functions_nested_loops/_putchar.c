#include <unistd.h>
/**
 * _putchar - Write the character c to the stdout
 * @c: The character to be printed
 * Return: 1 if true, or 0 if false
 * On error, -1 return
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
