#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>
void execute(char **argv)
{
	char *command = NULL, *actcmd = NULL;
	if (argv)
	{
		command = argv[0];
		actcmd = which(command);
	}
	if (execve(actcmd, argv, NULL) == -1)
	{
		perror("error");
	}
}
