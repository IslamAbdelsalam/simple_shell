#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <math.h>
#include <dirent.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>

#define checkExe execve(info->path, info->argv, Environment(info))
#define passPath getEnvironment(info, "PATH=")
#define check !delimiterChecker(str[i], d)
#define check2 (delimiterChecker(str[i + 1], d) || !str[i + 1])
#define BUFFER_SR 1024
#define BUFFER_SW 1024
#define maxWC 100
#define negativeOne -1
#define REGULAR_EXEP_FLAG 0
#define ORING_FLAG 1
#define andingFLAG 2
#define NULL_INFO                          \
	{                                     \
		NULL, NULL, NULL, 0, 0, 0, 0,     \
			NULL, NULL, NULL, NULL, NULL, \
			0, 0, NULL, 0, 0, 0           \
	}

extern char **environ;
#define chFLAG 3
#define B_CH_LOW 1
#define B_CH_UN 2
#define GLINE 0
#define HISTORY_FILE ".srHistory"
#define HISTORY_MAX_SIZE 4096

/**
 * struct list - singly linked list
 * @str: a string
 * @num: a number
 * @next: next node pointer
 */
typedef struct list
{
	int num;
	char *str;
	struct list *next;
} singleList;

/**
 * struct NodeINFO - This struct contains
 *						information about the execution context of a shell program.
 *
 * @arg: A pointer to a null-terminated string that represents
 *				the argument to the current command being executed.
 * @argv: An array of strings that represents the arguments
 *			passed to the shell program.
 * @path: A pointer to a null-terminated string that represents
 *			the full path to the executable file for the current command
 * @argc: An integer that represents the number of arguments
 *			passed to the shell program.
 * @lines: A variable of type `size_t` that represents
 *			the number of lines of input entered by the user.
 * @error_code: An integer that represents the error code of
 *				the last executed command.
 * @lc_flag: An integer flag that represents whether or not the last character
 *				of the input was a newline character.
 * @prog_name: A pointer to a null-terminated string that
 *				represents the name of the shell program.
 * @env: A pointer to a singly linked list that represents
 *			the environment	variables set for the shell program.
 * @history: A pointer to a singly linked list that represents
 *				the command history of the shell program.
 * @alias: A pointer to a singly linked list that represents
 *			the aliases set for the shell program.
 * @environ: An array of strings that represents the environment variables
 *				set for the shell program.
 * @env_changed: An integer flag that represents whether or not the environment
 *					variables have been changed.
 * @status: An integer that represents the exit status of
 *					the last executed command.
 * @sep_buff: An array of strings that represents
 *				the command arguments after being separated by a delimiter.
 * @sep_buff_kind: An integer that represents the type of delimiter
 *						used to separate command arguments.
 * @fd_read: An integer that represents the file d
 *				escriptor for the input stream.
 * @hist_lines: An integer that represents the number of history
 *					lines to display.
 */

typedef struct NodeINFO
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	size_t lines;
	int error_code;
	int lc_flag;
	char *prog_name;
	singleList *env;
	singleList *history;
	singleList *alias;
	char **environ;
	int env_changed;
	int status;

	char **sep_buff;
	int sep_buff_kind;
	int fd_read;
	int hist_lines;
} NodeInfo;

/**
 * struct current - This struct represents a current command.
 *
 * @type: A pointer to a null-terminated string
 *			that represents the type of the current command.
 * @func: A function pointer to the function that executes the current command.
 */

typedef struct current
{
	char *type;
	int (*func)(NodeInfo *);
} current_commands;

int shell(NodeInfo *info, char **argumentV);
int wChar(char c, int fd);
int wChars(char *str, int fd);
int sLen(char *s);
int sCmp(char *s1, char *s2);
int p_ch_error(char);
int _putchar(char);
int _isalpha(int);
int _atoi(char *);
int erorrNumber(char *);
int _exit_excution(NodeInfo *);
int _cd(NodeInfo *);
int _help(NodeInfo *);
int _history(NodeInfo *);
int _alias_(NodeInfo *);
int getLin(NodeInfo *, char **, size_t *);
int printEnv(NodeInfo *);
int checkEnv(NodeInfo *);
int chUnSetEnv(NodeInfo *);
int unSetEnv(NodeInfo *, char *);
int setEnvironment(NodeInfo *, char *, char *);
void putsError(char *);
void _puts(char *);
char *scat(char *, char *);
char *scpy(char *, char *);
char *sDup(const char *);
char *sNoCpy(char *, char *, int);
char *sNoCat(char *, char *, int);
char *schr(char *, char);
char *memory_set(char *, char, unsigned int);
void *reallocation(void *ptr, unsigned int old_size, unsigned int new_size);
char *getEnvironment(NodeInfo *, const char *);
char *_startWith(const char *, const char *);
char *dublicatedChars(char *, int, int);
char *isFileInPath(NodeInfo *info, char *pathstr, char *cmd);
char *convertToBase(long int, int, int);
char *readingHistory_1(NodeInfo *info);
char **Environment(NodeInfo *);
char **strTokenization(char *, char *);
char **toVector(singleList *);
void isCommandOk(NodeInfo *info);
void createProc(NodeInfo *info);
void handle_sigint(int);
void clear_info(NodeInfo *);
void set_info(NodeInfo *, char **);
void free_info(NodeInfo *, int);
void free_vector(char **);
void print_error(NodeInfo *, char *);
void handle_comments(char *);
void free_list(singleList **);
void check_chain(NodeInfo *info, char *buf, size_t *p, size_t i, size_t len);
int handle_builtin(NodeInfo *);
bool is_executable(NodeInfo *, char *);
int loophsh(char **);
int bfree(void **);
int from_terminal(NodeInfo *);
int print_dec(int, int);
int gather_env(NodeInfo *);
int create_history(NodeInfo *info);
int readingHistory_2(NodeInfo *info);
int history_update(NodeInfo *info, char *buf, int linecount);
int historyNo(NodeInfo *info);
int deleteNode(singleList **, unsigned int);
bool isChainge(NodeInfo *, char *, size_t *);
int chAlias(NodeInfo *);
int replaceVarToks(NodeInfo *);
int replaceString(char **, char *);
singleList *addNodeAtBegain(singleList **head, const char *str, int num);
singleList *addNodeToTail(singleList **head, const char *str, int num);
singleList *strStartPerfix(singleList *, char *, char);
size_t strNodeContent(const singleList *);
size_t listLength(const singleList *);
size_t printList(const singleList *);
ssize_t getInputTillLine(NodeInfo *);
ssize_t nodeIndex(singleList *, singleList *);
char **strSplitter(char *str, char *separators, size_t *word_count);
int allWc(char *str, char *separators, unsigned int *arr);
void setIntToZeros(unsigned int *arr, size_t size);
void nullStr(char *arr, size_t size);
bool delimiterChecker(char c, char *delimiters);

#endif /* SHELL_H */

