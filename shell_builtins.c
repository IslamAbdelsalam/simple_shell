#include "shell.h"

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(NodeInfo *info, char *str)
{
	char *p, c;
	int ret;

	p = schr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = deleteNode(&(info->alias),
							   nodeIndex(info->alias, strStartPerfix(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Sets an alias to a string.
 * @info: The parameter struct that contains information
 * @str: The string to be assigned as the alias.
 *
 * Return: Always 0 on success, 1 on error.
 */
int set_alias(NodeInfo *info, char *str)
{
	char *p;

	p = schr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (addNodeToTail(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - display alias string
 * @node: alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(singleList *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = schr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias_ - imitates the behavior of the alias built-in command.
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 *	Return: Always 0
 */
int _alias_(NodeInfo *info)
{
	int i = 0;
	char *p = NULL;
	singleList *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = schr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(strStartPerfix(info->alias, info->argv[i], '='));
	}
	return (0);
}

/**
 * chAlias - replaces aliases in tokinized string
 * @info: parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int chAlias(NodeInfo *info)
{
	int i;
	singleList *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = strStartPerfix(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = schr(node->str, '=');
		if (!p)
			return (0);
		p = sDup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}

	return (1);
}
