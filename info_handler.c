#include "shell.h"
/**
 * clear_info - clears NodeInfo struct fields
 * @info: struct address
 */
void clear_info(NodeInfo *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * set_info - sets NodeInfo struct fields
 * @info: struct address
 * @argumentV: argument vector
 */
void set_info(NodeInfo *info, char **argumentV)
{
	int i = 0;

	info->prog_name = argumentV[0];
	if (info->arg)
	{
		info->argv = strTokenization(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = sDup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;
		chAlias(info);
		replaceVarToks(info);
	}
}
/**
 * free_info - node info free
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(NodeInfo *info, int all)
{
	free_vector(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->sep_buff)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		free_vector(info->environ);
		info->environ = NULL;
		bfree((void **)info->sep_buff);
		if (info->fd_read > 2)
			close(info->fd_read);
		_putchar(negativeOne);
	}
}
