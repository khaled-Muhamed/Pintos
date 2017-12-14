#ifndef COMMAND_EXECUTER_H   /* Include guard */
#define COMMAND_EXECUTER_H

/* 
	- This method is responsible for creating child process to execute a command 
		required by user only if it run in foreground.
	- So this method is to user background method to check if it is in background
		or not.
*/
bool crteate_child_execute_command(char** args); 

/* 
	- This method will execute the command entered
	      >>it will try different paths to execute 
	         according to position of command file.
	- So this method is to try different paths in aloop.
*/
void execute();

/* -This method is used to check if command run in background
	or not.
*/
bool background();

#endif // COMMAND_EXECUTER_H
