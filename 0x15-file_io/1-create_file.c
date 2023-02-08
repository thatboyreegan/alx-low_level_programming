#include "main.h"
/**
*create_file - creates a file.
*@filename: name of file to create.
*@text_content: string to add to file.
*Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
	int fd, letters, mode;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (letters = 0; text_content[letters]; letters++)
		;

	mode = write(fd, text_content, letters);

	if (mode == -1)
		return (-1);

	close(fd);

	return (1);
}
