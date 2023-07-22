#include "main.h"

int main(void)
{
	while (1)
	{
		printf("$ ");
		char *line = our_get_line();
		char **tokens = our_strtok(line);

		if(tokens[0] != NULL)
		{
			execute(tokens);
		}

		free(tokens);
		free(line);
	}

}
