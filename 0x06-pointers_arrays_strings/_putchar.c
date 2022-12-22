/**
 * _putchar - writes a character to stdout.
 * @c: character to print.
 *
 * Return: 1 on success, -1 on error and error is set.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
