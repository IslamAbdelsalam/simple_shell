#include "shell.h"

/**
 * shell - Main control function for the shell program.
 * @info: parameter struct
 * @argumentV: array of string.
 *
 * Return: The status of the last executed builtin command.
 */
int shell(NodeInfo *info, char **argumentV)
{
	ssize_t read_result = 0;
	int builtin_return_value = 0;

	while (read_result != -1 && builtin_return_value != -2)
	{
		clear_info(info);
		if (from_terminal(info))
			_puts("$ ");
		p_ch_error(negativeOne);
		read_result = getInputTillLine(info);
		if (read_result != -1)
		{
			set_info(info, argumentV);
			builtin_return_value = handle_builtin(info);
			if (builtin_return_value == -1)
				isCommandOk(info);
		}
		else if (from_terminal(info))
			_putchar('\n');

		free_info(info, 0);
	}
	create_history(info);
	free_info(info, 1);
	if (!from_terminal(info) && info->status)
		exit(info->status);
	if (builtin_return_value == -2)
	{
		if (info->error_code == -1)
			exit(info->status);
		exit(info->error_code);
	}
	return (builtin_return_value);
}

/**
 * handle_builtin - Finds a builtin command.
 * @info: The parameter and return info struct that contains
 *			information about the current execution context.
 *
 * Return:
 * -1 if the builtin command is not found,
 * 0 if the builtin command executed successfully,
 * 1 if the builtin command was found but not successful,
 * 2 if the builtin command signals exit().
 */
int handle_builtin(NodeInfo *info)
{
	int i, builtin_return_value = -1;

	current_commands builtints[] = {
		{"cd", _cd},
		{"env", printEnv},
		{"exit", _exit_excution},
		{"help", _help},
		{"alias", _alias_},
		{"setenv", checkEnv},
		{"history", _history},
		{"unsetenv", chUnSetEnv},
		{NULL, NULL}};

	for (i = 0; builtints[i].type; i++)
		if (sCmp(info->argv[0], builtints[i].type) == 0)
		{
			info->lines++;
			builtin_return_value = builtints[i].func(info);
			break;
		}
	return (builtin_return_value);
}
