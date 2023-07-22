#include "main.h"

char **path_tokenize(char *path)
{
	int buf = 512, newbuf = 0, i = 0;
	char **tokens = NULL, *token = NULL;
	char **token_realloc = NULL;
	tokens = malloc(sizeof(char*) * buf);
	if (tokens == NULL)
	{
		return (-1);
	}

	token = strtok(path, " \n\t\r");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= buf)
		{
			newbuf = 512 * 2;
			tokens_realloc = tokens;
			tokens = _realloc(tokens, buf, (newbuf * sizeof(char *)));
			if (tokens == NULL)
			{
				free(tokens_realloc);
				free(tokens);
				return (-1);
			}
		}

		token = strtok(NULL, " \n\t\r");
	}

	tokens[i] = NULL;
	return(tokens);
}
