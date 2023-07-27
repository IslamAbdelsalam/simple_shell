#include "shell.h"

/**
 * _exit_excution - exits the shell
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int _exit_excution(NodeInfo *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = erorrNumber(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			putsError(info->argv[1]);
			p_ch_error('\n');
			return (1);
		}
		info->error_code = erorrNumber(info->argv[1]);
		return (-2);
	}
	info->error_code = -1;
	return (-2);
}
/**
 * _cd - changes the current directory of the process
 * @info: contains simulated arguments for a function pointer,
 *		  allowing for a consistent function prototype
 *
 * Return: 0
 */

int _cd(NodeInfo *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = getEnvironment(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = getEnvironment(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (sCmp(info->argv[1], "-") == 0)
	{
		if (!getEnvironment(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getEnvironment(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = getEnvironment(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		putsError(info->argv[1]), p_ch_error('\n');
	}
	else
	{
		setEnvironment(info, "OLDPWD", getEnvironment(info, "PWD="));
		setEnvironment(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - prints a message for aa function not implemented
 * @info:	contains simulated arguments for a function pointer,
 *			constant function prototype.
 * Return: 0
 */

int _help(NodeInfo *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);

	return (0);
}

/**
 * _history - prints the past commands
 * @info: parameter struct that contains information
 *	Return: Always 0
 */

int _history(NodeInfo *info)
{
	printList(info->history);

	return (0);
}
