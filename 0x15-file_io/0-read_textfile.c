#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to standard output.
 * @filename: PNT => name OF FL
 * @bytes_to_read: num of bytes.
 * Return: FIALS&NULL => 0.
 *         Otherwise - num of bytes.
 */
ssize_t read_textfile(const char *filename, size_t bytes_to_read)
{
	ssize_t file_descriptor, bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * bytes_to_read);
	if (buffer == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	bytes_read = read(file_descriptor, buffer, bytes_to_read);
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (file_descriptor == -1 || bytes_read == -1 || bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(file_descriptor);

	return (bytes_written);
}
