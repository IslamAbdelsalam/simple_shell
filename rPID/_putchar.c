#include "main.h"

/**
 * _putchar - print character
 * @c: character to be printed
 * Return: integer
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
