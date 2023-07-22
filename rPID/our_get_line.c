#include "main.h"

char *our_get_line()
{
	char *line = NULL;
	size_t strlen = 0;
	getline(&line, &bstrlen, stdin);
	return (line);
}
