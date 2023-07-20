#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>
int main(void)
{
	char *prompt_sign = "$ ";
	char *line;
	size_t size = 0;
	int bytesread;

	while (1)
	{
		printf("%s", prompt_sign);
		bytesread = getline(&line, &size, stdin);
		if (bytesread == -1)
		{
			return (-1);
		}
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
