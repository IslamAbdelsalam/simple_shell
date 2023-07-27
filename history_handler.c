#include "shell.h"

/**
 * readingHistory_1 - read the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *readingHistory_1(NodeInfo *info)
{
	char *buf, *dir;

	dir = getEnvironment(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (sLen(dir) + sLen(HISTORY_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	scpy(buf, dir);
	scat(buf, "/");
	scat(buf, HISTORY_FILE);
	return (buf);
}

/**
 * create_history - creates a history file or add to it
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int create_history(NodeInfo *info)
{
	ssize_t fd;
	char *filename = readingHistory_1(info);
	singleList *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		wChars(node->str, fd);
		wChar('\n', fd);
	}
	wChar(negativeOne, fd);
	close(fd);
	return (1);
}

/**
 * readingHistory_2 - reads history from file
 * @info: the parameter struct
 *
 * Return: history lines on success, 0 otherwise
 */
int readingHistory_2(NodeInfo *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = readingHistory_1(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			history_update(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		history_update(info, buf + last, linecount++);
	free(buf);
	info->hist_lines = linecount;
	while (info->hist_lines-- >= HISTORY_MAX_SIZE)
		deleteNode(&(info->history), 0);
	historyNo(info);
	return (info->hist_lines);
}

/**
 * history_update - writes to history file
 * @info: parameter struct
 * @buf: the string to be written
 * @linecount: the line number
 *
 * Return: Always 0
 */
int history_update(NodeInfo *info, char *buf, int linecount)
{
	singleList *node = NULL;

	if (info->history)
		node = info->history;
	addNodeToTail(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * historyNo - updates the history line numbers
 * @info: parameter struct
 *
 * Return: the number of history lines
 */
int historyNo(NodeInfo *info)
{
	singleList *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->hist_lines = i);
}

