#include "main.h"

int main((void)int ac, char **argv)
{
	char *prompt_sign = "$ ";
	char *line, *linecopy,, *token, *delim = " \n", **strarr;
	size_t size = 0;
	int bytesread, tokennum = 0, i;

	while (1)
	{
		printf("%s", prompt_sign);
		bytesread = getline(&line, &size, stdin);
		if (bytesread == -1)
		{
			return (-1);
		}
		linecopy = malloc(sizeof(char) * bytesread);
		if (linecopy == NULL)
		{
			return (-1);
		}

		linecopy = strcpy(linecopy, line);
		token = strtok(line, delim);
		while (token != NULL)
		{
			tokennum++;
			token = strtok(NULL, delim);
		}
		tokennum++;
		strarr = malloc(sizeof(char *) * tokennum);
		if (strarr == NULL)
		{
			return (-1);
		}
		token = strtok(linecopy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			if (argv[i] == NULL)
			{
				return (-1);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		//execute(argv);

	}
	printf("%s\n", line);
	free(linecopy);
	free(line);
	return (0);
}
