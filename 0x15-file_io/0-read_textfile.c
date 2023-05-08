#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX STDOUT
 * @letters: Max Numbers
 * Return: Count printed letters, 0 for errors
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fld;
	ssize_t num_read, nWR, tWR;
	char *buf;

	if (filename == NULL)
		return (0);

	fld = open(filename, O_RDONLY);
	if (fld == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL) {
		close(fld);
		return (0);
	}

	tWR = 0;
	while ((num_read = read(fld, buf, letters)) > 0) {
		nWR = write(STDOUT_FILENO, buf, num_read);
		if (nWR == -1) {
			free(buf);
			close(fld);
			return (0);
		}
		tWR += nWR;
	}

	if (num_read == -1) {
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fld);

	return (tWR);
}
