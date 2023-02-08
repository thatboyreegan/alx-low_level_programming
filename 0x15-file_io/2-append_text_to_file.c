#include "main.h"
/**
*append_text_to_file - appends a text to the end of a file.
*@filename: name of file.
*@text_content: string to add to the end of the file.
*Return: 1 on success and -1 on failure.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, letters, mode;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (letters = 0; text_content[letters]; letters++)
			;

	 mode = write(fd, text_content, letters);

		if (mode == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
