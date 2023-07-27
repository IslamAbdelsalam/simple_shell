#include "shell.h"
/**
 * isCommandOk - Searches for a command in
 *					PATH or the current directory
 * @info: parameter struct
 * Return: void
*/

void isCommandOk(NodeInfo *info)
{
	char *path = NULL;
	int i, word_count;

	info->path = info->argv[0];
	if (info->lc_flag == 1)
	{
		info->lines++;
		info->lc_flag = 0;
	}
	for (i = 0, word_count = 0; info->arg[i]; i++)
		if (!delimiterChecker(info->arg[i], " \t\n"))
			word_count++;
	if (!word_count)
		return;
	path = isFileInPath(info, passPath, info->argv[0]);
	if (path)
	{
		info->path = path;
		createProc(info);
	}
	else
	{
		if ((from_terminal(info)))
			createProc(info);
		else if (passPath || info->argv[0][0] == '/')
		{
			if (is_executable(info, info->argv[0]))
				createProc(info);
		}
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
