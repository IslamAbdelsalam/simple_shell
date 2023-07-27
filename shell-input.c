#include "shell.h"

/**
 * input_buf - Buffers chained commands.
 * @info: The parameter struct that contains information
 *			about the current execution context.
 * @buf: The address of the buffer to be used for input.
 * @len: The address of the variable that will store the length of the buffer.
 *
 * Return: The number of bytes read.
 */
ssize_t input_buf(NodeInfo *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing  fill the buffer */
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, handle_sigint);
#if GLINE
		r = getline(buf, &len_p, stdin);
#else
		r = getLin(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* remove newline */
				r--;
			}
			info->lc_flag = 1;
			handle_comments(*buf);
			history_update(info, *buf, info->hist_lines++);
			{
				*len = r;
				info->sep_buff = buf;
			}
		}
	}
	return (r);
}

/**
 * getInputTillLine - Gets a line of input without the newline character.
 * @info: The parameter struct that contains
 *			information about the current execution context.
 * Return: The number of bytes read.
 */
ssize_t getInputTillLine(NodeInfo *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(negativeOne);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (isChainge(info, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->sep_buff_kind = REGULAR_EXEP_FLAG;
		}
		*buf_p = p;
		return (sLen(p));
	}
	*buf_p = buf;
	return (r);
}

/**
 * read_buf - Reads a buffer.
 * @info: The parameter struct that contains information
 *			about the current execution context.
 * @buf: The buffer to be read.
 * @i: The size of the buffer.
 *
 * Return: r.
 */
ssize_t read_buf(NodeInfo *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->fd_read, buf, BUFFER_SR);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * getLin - Gets the next line of input from STDIN.
 * @info: The parameter struct that contains information
 * @ptr: The address of the pointer to the buffer to be used for input.
 * @length: The size of the preallocated ptr buffer, if it is not NULL.
 *
 * Return: The number of characters read.
 */
int getLin(NodeInfo *info, char **ptr, size_t *length)
{
	static char buf[BUFFER_SR];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);
	c = schr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = reallocation(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (s)
		sNoCat(new_p, buf + i, k - i);
	else
		sNoCpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * handle_sigint - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void handle_sigint(__attribute__((unused)) int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(negativeOne);
}
