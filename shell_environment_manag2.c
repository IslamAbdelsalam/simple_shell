#include "shell.h"

/**
 * getEnvironment -  environment variable value
 * @info: prameter struct contain information
 * @name: environment variable name
 *
 * Return: the value
 */

char *getEnvironment(NodeInfo *info, const char *name)
{
	char *p;
	singleList *node = info->env;

	while (node)
	{
		p = _startWith(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * checkEnv - is environment variable has been set?
 * @info: prameter struct contain information
 *
 * Return: 0 if set, else 1.
 */

int checkEnv(NodeInfo *info)
{
	if (info->argc != 3)
	{
		putsError("Incorrect number of arguements\n");
		return (1);
	}

	if (setEnvironment(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * chUnSetEnv - rm environment variable
 * @info: prameter struct contain information
 * Return: Always 0
 */
int chUnSetEnv(NodeInfo *info)
{
	int i;

	if (info->argc == 1)
	{
		putsError("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		unSetEnv(info, info->argv[i]);

	return (0);
}

/**
 * gather_env - populates env linked list
 * @info: struct containing arguments
 * Return: Always 0
 */
int gather_env(NodeInfo *info)
{
	singleList *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		addNodeToTail(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * printEnv - display environment variable
 * @info: prameter struct contain information
 * Return: Always 0
 */
int printEnv(NodeInfo *info)
{
	strNodeContent(info->env);
	return (0);
}
