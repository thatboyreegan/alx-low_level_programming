#include "main.h"
/**
*read_textfile - reads a textfile and prints the letters.
*@filename: name of file.
*@letters: number of letters printed.
*Return: number of letters printed or 0 if failure.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t new, num;
	char *tmp;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	tmp = malloc(sizeof(char) * (letters));
	if (!tmp)
		return (0);

new = read(fd, tmp, letters);
num = write(STDOUT_FILENO, tmp, new);

	close(fd);

	free(tmp);

	return (num);
}
