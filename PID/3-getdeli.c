#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *input;
	size_t bufsize = 32;

	input = (char *)malloc(sizeof(char) * bufsize);
	
	if(input == NULL)
	{
		perror("Unable to allocate buffer\n");
		exit(1);
	}

	printf("%s", "$ ");
	int readLen = getdelim(&input,&bufsize,EOF,stdin);
	printf("%s", input); //check if we take it or not

	return (0);
}
