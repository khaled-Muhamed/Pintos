#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include "command_parser.c"
typedef int bool;
#define true 1;
#define false 0;

int main() {

	const char commandLine[100];
	bool loop = true ;
	int childExitStatus;
	pid_t pid;
	char *args[3];
	
	scanf("%[^\n]%*c", commandLine);
	parse_command(commandLine);

	//char * const parmList[] = { "-l", home , NULL };
/*	while ( loop ) {
		
		args[0] = ( char *)"ls";
		args[1] = "-l";
		//args[2] = NULL;
		printf("SHELL>");
		scanf("%[^\n]%*c", commandLine);
		pid = fork();		
		if( pid == 0 ){
		 //child code goes here
	//execv("/bin/ls", parmList)
			execv("/bin/ls",args);
			perror("Error occurr");
	       }else{
			//parent code goes here

		//parent must wait child process till it execute the command.
		wait(&childExitStatus);
		printf("child end working cntrol returned \n");
		continue;
*/		} 
	

 }


return 0;
}
