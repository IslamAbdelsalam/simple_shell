#include "main.h"


int main(int argc, char *argv[], char *env[])
{
	char *buffer = NULL, *shprmpt = "$ ";
	unsigned int buffersize = 0, bytes;
	pid_t pid;
	int status;
	bool piped = false;
	struct stat statusbuffer; //struct stat  holds file metadata, extremely usefull, will save us a a lot of time

	while (1 && !piped)//we might need that later
	{
		//check if input is from the terminal or is piped
		if (isatty(STDIN_FILENO == 0))
		{
			piped = true;
		}

		//made _putchar & _puts beacuse printf is forbidden
		_puts(shprmpt);

		//they say getline is better than fgets and doc says we have to free memory allocated by getline
		bytes = getline(&buffer, &buffersize, stdin);
		
		if (bytes == -1)
		{
			perror("Couldn't Read Bytes");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (buffer[bytes - 1] == '\n')
		{
			buffer[bytes - 1] = '\0';
		}

		pid = fork();

		if (pid == -1)
		{
			perror("Can't Fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execute(buffer, &statusbuffer, env);
		}

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Can't Wait");
			exit(EXIT_FAILURE);
		}
	}

	free(buffer);
	return (0);
}

int _execute(char *args, struct stat *statusbuffer, char **envp)
{
	int argc;
	char **argv, *exec;

	argv = strtok(args, " ");
	//check if exec file exists
	if (!file_stat_check(argv[0], statusbuffer))
	{
		perror("Can't Get File Status");
		exit(EXIT_FAILURE);
	}

	execve(argv[0], argv, envp);

	perror("Can't Execute");
	exit(EXIT_FAILURE);
}

bool file_stat_check(char *pathname, struct stat *statusbuffer)
{
	int statusreturn;

	statusreturn = stat(pathname, &statusbuffer);

	if (statusreturn == 0)
	{
		return (true);
	}

	return (false);
}
