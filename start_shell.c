#include "shell.h"
/**
 * main - This function serves as the entry point to the shell program.
 * @argc: The number of arguments passed into the shell executable.
 * @argv: A vector that contains the arguments passed to the shell.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
	NodeInfo info[] = {NULL_INFO};
	int fd = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fd)
		: "r"(fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);

			if (errno == ENOENT)
			{
				putsError(argv[0]);
				putsError(": 0: Can't open ");
				putsError(argv[1]);
				p_ch_error('\n');
				p_ch_error(negativeOne);
				exit(127);
			}

			return (EXIT_FAILURE);
		}

		info->fd_read = fd;
	}

	gather_env(info);
	readingHistory_2(info);
	shell(info, argv);

	return (EXIT_SUCCESS);
}
