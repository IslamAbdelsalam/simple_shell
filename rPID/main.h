#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/wait.h>

char *which(char *cmd);
void execute(char **argv);
char *our_get_line();
#endif /*ifndef MAIN_H*/
