#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>
char *which(char *cmd)
{
	char *path, *pathcpy, *token, *filepath;
	int len, dirlen;
	struct stat buff;
	path = getenv("PATH");
	if (path)
	{
		pathcpy = strdup(path);
		len = strlen(cmd);
		token = strtok(pathcpy, ":");
		while (token != NULL)
		{
			dirlen = strlen(token);
			filepath = malloc(sizeof(char) * (len + dirlen + 2));
			strcpy(filepath, token);
			strcat(filepath, "/");
			strcat(filepath, cmd);
			strcat(filepath, "\0");
			if (stat(filepath, &buff) == 0)
			{
				free(pathcpy);
				return(filepath);
			}
			else
			{
				free(filepath);
				token = strtok(NULL, ":");
			}
		}

		free(pathcpy);
		if(stat(cmd, &buff) == 0)
		{
			return (cmd);
		}

		return (NULL);
	}
	return (NULL);
}
