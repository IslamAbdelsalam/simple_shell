#include "shell.h"
/**
 * memory_set - bytes of memory
 * @s: the pointer to the memory area
 * @b: byte to be filled
 * @n: amount of bytes to be filled
 * Return: s- a memory area pointer
 */
char *memory_set(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * free_vector - frees memory allocated
 * @vec: Vector to be freed.
 *
 * Return: Nothing.
 */

void free_vector(char **vec)
{
	char **ptr = vec;

	if (!vec)
		return;
	while (*vec)
		free(*vec++);

	free(ptr);
}

/**
 * reallocation - realloc memory
 * @ptr: pointer to the memory area
 * @old_size: byte size of old block
 * @new_size: size of new block
 * Return: pointer of old block.
 */
void *reallocation(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (!p)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

#include "shell.h"

/**
 * bfree - frees memory allocated
 * @ptr: pointer to the memory area
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

