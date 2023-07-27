#include "shell.h"

/**
 * setIntToZeros - zeros out an array of integers
 * @arr: initialized array.
 * @size: Size of the array.
 *
 * Return: Nothing
 */

void setIntToZeros(unsigned int *arr, size_t size)
{
	size_t x;

	for (x = 0; x < size; x++)
		arr[x] = 0;
}

/**
 * nullStr - nulls out an array of characters
 * @arr: Array to be initialized.
 * @size: Size of the array.
 *
 * Return: Nothing
 */

void nullStr(char *arr, size_t size)
{
	size_t x;

	for (x = 0; x < size; x++)
		arr[x] = '\0';
}
