#include <stdio.h>
#include <string.h>

int main(int ac, char *av)
{
	 // Returns first token
    char* token = strtok(av, " ");
 
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        printf(" %s\n", token);
        token = strtok(av, " ");
    }
	return (0);
}
