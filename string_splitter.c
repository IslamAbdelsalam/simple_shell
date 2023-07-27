#include "shell.h"

/**
 * strSplitter - Splits a string into words.
 * @str: String to be split.
 * @separators: Delimiters used to split the string.
 * @word_count: Pointer to store the number of words.
 *
 * Return: Pointer to a vector of strings (words).
 */

char **strSplitter(char *str, char *separators, size_t *word_count)
{
	int v, no_of_words;
	char **words;
	char *str_ptr = str;
	unsigned int c, word_sizes[maxWC];

	setIntToZeros(word_sizes, maxWC);
	no_of_words = allWc(str, separators, word_sizes);

	if (no_of_words == 0)
		return (NULL);

	words = malloc((sizeof(char *) * no_of_words) + 1);
	if (!words)
		return (NULL);

	for (v = 0; v < no_of_words; v++)
	{
		words[v] = malloc((sizeof(char) * word_sizes[v]) + 1);
		if (!words[v])
		{
			for (v--; v >= 0; v--)
				free(words[v]);
			free(words);
			return (NULL);
		}
		for (c = 0; c < word_sizes[v]; c++, str_ptr++)
		{
			while (delimiterChecker(*str_ptr, separators))
				str_ptr++;

			words[v][c] = *str_ptr;
		};
		words[v][c] = '\0';
	}
	*word_count = no_of_words;
	words[v] = NULL;
	return (words);
}

#include "shell.h"
/**
 * strTokenization - splits a string into words
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strTokenization(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (check && check2)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (delimiterChecker(str[i], d))
			i++;
		k = 0;
		while (!delimiterChecker(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
