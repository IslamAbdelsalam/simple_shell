#include "shell.h"
/**
 * erorrNumber - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string,
 * converted integer else -1
 *
 */
int erorrNumber(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_error - prints an error message
 * @inf: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string,
 * converted integer else -1
 */
void print_error(NodeInfo *inf, char *estr)
{
	putsError(inf->prog_name);
	putsError(": ");
	print_dec(inf->lines, STDERR_FILENO);
	putsError(": ");
	putsError(inf->argv[0]);
	putsError(": ");
	putsError(estr);
}
/**
 * print_dec - convert to base 10
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_dec(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = p_ch_error;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{

		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * convertToBase - convert to the base of choice
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convertToBase(long int num, int base, int flags)
{
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	static char *array;
	static char buffer[50];

	if (!(flags & B_CH_UN) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & B_CH_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * handle_comments - remove comments from a string
 * @buf: the string
 *
 * Return: 0;
 */

void handle_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
