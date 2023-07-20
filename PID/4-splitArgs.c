#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	for(int i = 1; av[i] != NULL; i++)
	{
		for(int j = 0; av[i][j] != '\0'; j++)
			putchar(av[i][j]);
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
