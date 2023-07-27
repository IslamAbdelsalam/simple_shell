#include "shell.h"

/**
 * is_executable - Determines whether a file is an executable command.
 * @info: The info struct that contains information
 *			about the current execution context.
 * @path: The path to the file to be checked.
 *
 * Return: 1 if the file is an executable command, 0 otherwise.
 */
bool is_executable(NodeInfo *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (true);
	}
	return (false);
}

/**
 * dublicatedChars - Duplicates characters in a string.
 * @pathstr: The string to be duplicated.
 * @start: The starting index of the characters to be duplicated.
 * @stop: The stopping index of the characters to be duplicated.
 *
 * Return: A pointer to the new buffer
 *				containing the duplicated characters.
 */
char *dublicatedChars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * isFileInPath - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *isFileInPath(NodeInfo *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((sLen(cmd) > 2) && _startWith(cmd, "./"))
	{
		if (is_executable(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dublicatedChars(pathstr, curr_pos, i);
			if (!*path)
				scat(path, cmd);
			else
			{
				scat(path, "/");
				scat(path, cmd);
			}
			if (is_executable(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
