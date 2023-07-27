#include "shell.h"
/**
 * putsError - display input string
 * @str: the string
 *
 * Return: Nothing
 */
void putsError(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		p_ch_error(str[i]);
		i++;
	}
}
/**
 * p_ch_error - writes the c char to stderr
 * @c: what we need to print
 *
 * Return: On success 1.
 * On failure, -1 is returned
 */
int p_ch_error(char c)
{
	static int i;
	static char buf[BUFFER_SW];

	if (c == negativeOne || i >= BUFFER_SW)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != negativeOne)
		buf[i++] = c;
	return (1);
}
/**
 * wChar - write character c to fd
 * @c: The character to print
 * @fd: The fd to write to
 *
 * Return: On success 1.
 * On failure, -1 is returned
 */
int wChar(char c, int fd)
{
	static int i;
	static char buf[BUFFER_SW];

	if (c == negativeOne || i >= BUFFER_SW)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != negativeOne)
		buf[i++] = c;
	return (1);
}
/**
 * wChars - print the input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int wChars(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += wChar(*str++, fd);
	}
	return (i);
}
