#include "main.h"

/**
 * create_file -This creates a text files
 * @f_name: this is a pointer to a file created.
 * @content: this is a pointer to a string created.
 * Return: 1 if sucess and -1 otherwise
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
