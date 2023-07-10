#include "main.h"

/**
 * append_text_to_file - this apends text at the end of a files.
 * @filename: this is a pointer to a given files.
 * @text_content: This is a pointer to a given string.
 * Return: 1 on sucess and -1 when fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ro, wr;
	int len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	ro = open(filename, O_WRONLY | O_APPEND);
	wr = write(ro, text_content, len);

	if (ro == -1 || wr == -1)
		return (-1);

	close(ro);

	return (1);
}
