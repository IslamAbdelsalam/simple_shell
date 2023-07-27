#include "shell.h"

/**
 * Environment - Returns a copy of the environment
 *					variables as an array of strings.
 * @info: Structure containing the environment variables.
 *		  Used to maintain constant function prototype.
 * Return: The environment variables as an array of strings.
 */

char **Environment(NodeInfo *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = toVector(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * setEnvironment - change environment variable.
 * @info: prameter struct contain information
 * @var: environment variable to add or update.
 * @value: Value of environment variable to add or update.
 * Return: 0 if the environment variable was successfully
 */

int setEnvironment(NodeInfo *info, char *var, char *value)
{
	char *buf = NULL;
	singleList *node;
	char *p;

	if (!var || !value)
		return (1);

	buf = malloc(sLen(var) + sLen(value) + 2);
	if (!buf)
		return (1);

	scpy(buf, var);
	scat(buf, "=");
	scat(buf, value);

	node = info->env;
	while (node)
	{
		p = _startWith(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	addNodeToTail(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

/**
 * unSetEnv - Removes an environment variable.
 * @info: Structure containing the environment variables.
 *		  Used to maintain constant function prototype.
 * @var: The name of the environment variable to remove.
 * Return: 1 if the environment variable was successfully removed, else 0.
 */
int unSetEnv(NodeInfo *info, char *var)
{
	singleList *node = info->env;
	size_t index = 0;
	char *p;

	/* Return 0 if the environment variables or variable name are not defined. */
	if (!node || !var)
		return (0);

	/* Loop through each environment variable. */
	while (node)
	{
		/* Check if the current variable matches the name to be removed. */
		p = _startWith(node->str, var);
		if (p && *p == '=')
		{
			/* Remove the current variable from the list. */
			info->env_changed = deleteNode(&(info->env), index);

			/* Reset the index and continue to the next variable. */
			index = 0;
			node = info->env;
			continue;
		}

		/* Move to the next variable in the list. */
		node = node->next;
		index++;
	}

	return (info->env_changed);
}
