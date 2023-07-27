#include "shell.h"
/**
 * createProc - Forks a new process to run the command.
 * @info: prameter struct
 *
 * Return: void.
*/

void createProc(NodeInfo *info)
{
	pid_t cpid;

	cpid = fork();
	if (cpid == -1)
	{
		perror("Error:");
		return;
	}
	if (cpid == 0)
	{
		if (checkExe == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);

			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
