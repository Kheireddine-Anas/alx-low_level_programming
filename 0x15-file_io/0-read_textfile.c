#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 * Return: actual number of letters read and printed, or 0 if error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t nread;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		free(buffer);
		return (0);
	}
	
	nread = fread(buffer, sizeof(char), letters, file);
	if (nread == 0)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	size_t nwritten = fwrite(buffer, sizeof(char), nread, stdout);
	if (nwritten != nread)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	free(buffer);
	fclose(file);
	return (nwritten);
}
