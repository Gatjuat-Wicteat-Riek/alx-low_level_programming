#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - this allocates 1024 bytes to a buffer.
 * @file: this is a name of a file to a buffer.
 * Return: this is a pointer to a buffer
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - this closes a file descriptors
 * given in a program.
 * @fd: This is a file descriptor in a program.
 */
void close_file(int fd)
{
	int ch;

	ch = close(fd);

	if (ch == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - this is a copies of a main.
 * @argc: The number of agument in a program
 * @argv: this is a pointer to an array
 * Return: return 0 on sucess and 1 if failed
 * Description: exits code 97 if the agument counts is correct.
 * exit code 98 if fails to read and write.
 * exits code 99 if fails to write
 * exits code 100 if fails.
 */
int main(int argc, char *argv[])
{
	int fm, t, rw, wr;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	fm = open(argv[1], O_RDONLY);
	rw = read(fm, buff, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while (rw > 0)
	{
		if (fm == -1 || rw == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wr = write(t, buff, rw);
		if (t == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		rw = read(fm, buff, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	}

	free(buff);
	close_file(fm);
	close_file(t);

	return (0);
}
