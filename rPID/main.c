#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>
// okay lets say what we're doing here
//im trying out things. nothing is complete here
//first main function
int main(void)
{
	//inifinte loop because you wanna keep getting input
	//while(1)
	{
		//read input
		//store it in buffer
			//i need smth to refer to when reading the line
			//line itself is a string
			//read as string
		//tokenize the buffer
			//when i tokenize the string with strtok
			//it will put \0 between every word
			//which means the buffer is no longer a string
			//the buffer is now an array of strings
		//execute the tokens?
			//so for every token in the buffer
			//i need to check if it exists(PATH)
			//if it does, then i fork my main process
			//to execute the argument and
			//i use execve for that
		//repeat
		//================================================
		//TASK 1: FOCUS
		//Display a prompt and wait for the user to type a command. A command line always ends with a new line.
			//while true
			//printf $
			//read input line
		//The prompt is displayed again each time a command has been executed.
			//when child process terminates(?)
			//printf $
		//The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
		//The command lines are made only of one word. No arguments will be passed to programs.
			//only the command
		//If an executable cannot be found, print an error message and display the prompt again.
		//Handle errors.
			//smth not existing
			//signals, interrupts
			//-1 file descriptors/return values
			//memory leaks
		//You have to handle the “end of file” condition (Ctrl+D)
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		//READ INPUT: (i will use getline, sounds easier and safer)
		//getline allocates using MALLOC SO WE SHOULD FREE WHATEVER getline() MALLOCED
		//char *_our_getline()
		//{
			//char *line = NULL;//brand new line nothing typed it
			//int len = 0; //because we dont know the length of the input
			//getline(&line, &len, stdin) //line = NULL so getline will allocate required memory for input
						      //len is pointer so that its passed by refernce and buffer length actually changes
						      //read from standard input
			//return (line);
		//}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		//TOKENIZE INPUT:
		//char **tokenize (char *line)
		//{
			//char *tok = strtok(line, delimiter); //delimiter will be space or \n
			//
		//}
	}
}
