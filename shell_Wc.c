#include "shell.h"

/**
 * allWc - it act like wc in linux
 * @str: String to be parsed.
 * @separators: One or more delimiters.
 * @arr: Pointer to array where the word lengths will be stored.
 *
 * Return: Number of words.
 */

int allWc(char *str, char *separators, unsigned int *arr)
{
	if (!str)
	{
		return (0);
	}

	int word_count = 0;
	bool inside_word = false;
	char *p = str;

	while (*p != '\0')
	{
		if (strchr(separators, *p) != NULL)
		{
			inside_word = false;
		}
		else if (!inside_word)
		{
			inside_word = true;
			arr[word_count++] = 1;
		}
		else
		{
			arr[word_count - 1]++;
		}
		p++;
	}

	return (word_count);
}
