#include "main.h"

/**
 * _puts - print string
 * @s: char pointer
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
