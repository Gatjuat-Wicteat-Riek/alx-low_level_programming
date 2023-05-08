#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- This reads text  printed to STDOUT.
 * @f_name: This is atext files to be read.
 * @letters: This is a number of character to be read.
 * Return: return w if success
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
