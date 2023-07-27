#include "shell.h"
/**
 * isChainge - Tests whether the current character
 *				in the buffer is a chain delimiter.
 * @info: The parameter struct that contains information
 *			about the current execution context.
 * @buf: The character buffer that contains the input string.
 * @p: The address of the current position in the buffer.
 *
 * Return: 1 if the current character is a chain delimiter, otherwise 0.
 */
bool isChainge(NodeInfo *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->sep_buff_kind = ORING_FLAG;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->sep_buff_kind = andingFLAG;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->sep_buff_kind = chFLAG;
	}
	else
		return (false);
	*p = j;
	return (true);
}

/**
 * check_chain - Checks whether we should continue
 *					chaining based on the last status.
 * @info: The parameter struct that contains information
 *			about the current execution context.
 * @buf: The character buffer that contains the input string.
 * @p: The address of the current position in the buffer.
 * @i: The starting position in the buffer.
 * @len: The length of the buffer.
 *
 * Return: void.
 */
void check_chain(NodeInfo *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->sep_buff_kind == andingFLAG)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->sep_buff_kind == ORING_FLAG)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
 * replaceVarToks - Replaces variables in the tokenized string.
 * @info: The parameter struct that contains information
 *			about the current execution context.
 *
 * Return: 1 if the variables were replaced, 0 otherwise.
 */
int replaceVarToks(NodeInfo *info)
{
	int i = 0;
	singleList *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!sCmp(info->argv[i], "$?"))
		{
			replaceString(&(info->argv[i]),

						   sDup(convertToBase(info->status, 10, 0)));

			continue;
		}
		if (!sCmp(info->argv[i], "$$"))
		{
			replaceString(&(info->argv[i]),

						   sDup(convertToBase(getpid(), 10, 0)));

			continue;
		}
		node = strStartPerfix(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replaceString(&(info->argv[i]),

						   sDup(schr(node->str, '=') + 1));

			continue;
		}
		replaceString(&info->argv[i], sDup(""));
	}
	return (0);
}
/**
 * replaceString - Replaces the old string with the new string.
 * @old: The address of the old string.
 * @new: The new string.
 *
 * Return: 1 if the string was replaced, 0 otherwise.
 */
int replaceString(char **old, char *new)
{
	free(*old);
	*old = new;

	return (1);
}

