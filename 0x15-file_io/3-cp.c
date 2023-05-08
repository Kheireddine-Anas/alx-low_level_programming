#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* create_buffer - Allocates 1024 bytes for a buffer.
* @file: The name of the file buffer is storing chars for.
* Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(char *file)
{
char *buffer = malloc(1024 * sizeof(char));
if (buffer == NULL) {
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}
return (buffer);
}

/**
* close_file - Closes a file descriptor.
* @fd: The file descriptor to close.
*
*/
void close_file(int fd)
{
if (close(fd) == -1) {
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
}

/**
* main - Copies the content of a file to another file.
* @argc: The number of arguments passed to the program.
* @argv: An array of strings containing the program arguments.
*
* Return: 0 on success, or an exit code on failure.
*/
int main(int argc, char *argv[])
{
if (argc != 3) {
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

char *buffer = create_buffer(argv[2]);
int from = open(argv[1], O_RDONLY), to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

while (1) {
	ssize_t r = read(from, buffer, 1024);
	if (r == -1) {
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	} else if (r == 0) {
		break;
	}

	ssize_t w = write(to, buffer, r);
	if (w == -1) {
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}
}

close_file(from);
close_file(to);
free(buffer);

return (0);
}
