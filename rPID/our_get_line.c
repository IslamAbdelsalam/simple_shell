#include "main.h"

char *our_get_line()
{
	char *line = NULL;
	size_t strlen = 0, bytesread;
	bytesread = getline(&line, &bstrlen, stdin);
	if (bytesread == < 0)
	{
		free(line);
		return (0);
	}
	return (line);
}
