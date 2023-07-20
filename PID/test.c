#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS_SIZE 64

int main(int argc, char *argv[])
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS_SIZE];
	int status, i;

	while (1)
	{
		printf("$ ");
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			/* end of file condition */
			printf("\n");
			exit(0);
		}
		input[strlen(input) - 1] = '\0'; /* remove trailing newline */

		if (strcmp(input, "exit") == 0)
		{
			exit(0);
		}

		args[0] = strtok(input, " ");
		for (i = 1; i < MAX_ARGS_SIZE; i++)
		{
			args[i] = strtok(NULL, " ");
			if (args[i] == NULL)
			{
				break;
			}
		}
		args[i] = NULL; /* set the last argument to NULL */

		if (fork() == 0)
		{
			/* child process */
			if (access(args[0], X_OK) != 0)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				exit(1);
			}
			argv[0] = args[0];
			execve(args[0], args, NULL);
			perror(args[0]);
			exit(1);
		}
		else
		{
			/* parent process */
			wait(&status);
		}
	}

	return (0);
}
