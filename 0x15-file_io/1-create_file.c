#include "main.h"

/**
 * create_file - creates a new file and writes text content to it
 * @filename: the name of the file to create
 * @text_content: the content to write to the file (can be NULL)
 * Return: 1 if successful, or -1 if an error occurs
 */

int create_file(const char *filename, char *text_content)
{
	int fd, num_written, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = 0;
		while (text_content[len] != '\0')
			len++;
		num_written = write(fd, text_content, len);
		if (num_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
