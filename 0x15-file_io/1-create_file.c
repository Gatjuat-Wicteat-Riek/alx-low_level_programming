#include "main.h"

/**
 * create_file - Creates a file.
 * @f_name: A pointer to the name of the file to create.
 * @content: A pointer to a string to write to the file.
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *f_name, char *content)
{
	int number, w, counter = 0;

	if (f_name == NULL)
		return (-1);

	if (content != NULL)
	{
		for (counter = 0; content[counter];)
			counter++;
	}

	number = open(f_name, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(number, content, counter);

	if (number == -1 || w == -1)
		return (-1);

	close(number);

	return (1);
}
