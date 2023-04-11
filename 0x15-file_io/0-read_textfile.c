#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file that will printed to STDOUT.
 * @f_name: Text file to be read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *f_name, size_t letters)
{
	char *nff;
	ssize_t file;
	ssize_t w;
	ssize_t t;

	file = open(f_name, O_RDONLY);
	if (file == -1)
		return (0);
	nff = malloc(sizeof(char) * letters);
	t = read(file, nff, letters);
	w = write(STDOUT_FILENO, nff, t);

	free(nff);
	close(file);
	return (w);
}
