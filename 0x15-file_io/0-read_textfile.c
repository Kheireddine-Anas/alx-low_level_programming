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
	ssize_t fl_d, bt_rd, bt_wr;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * bytes_to_read);
	if (buffer == NULL)
		return (0);

	fl_d = open(filename, O_RDONLY);
	bt_rd = read(fl_d, buffer, bytes_to_read);
	bt_wr = write(STDOUT_FILENO, buffer, bt_rd);

	if (fl_d == -1 || bt_rd == -1 || bt_wr == -1 || bt_wr != bt_rd)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fl_d);

	return (bt_wr);
}
