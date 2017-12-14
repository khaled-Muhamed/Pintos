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

	const char* input;bool loop = true;int pid,childStatus;
	char* copy;
	char command[100]; 
	while(loop){	
	 fprintf(stdout,"SHELL>>");
 			/* Get the name, with size limit. */
 	       fgets (command, 100, stdin);

		    /* Remove trailing newline, if there. */
	       if ((strlen(command)>0) && (command[strlen (command) - 1] == '\n'))
			command[strlen (command) - 1] = '\0';
	
		input = command;
		printf("input is =%s\n",input);
		parse_command(input);
		/* create child that will execute the commands*/		
		pid = fork();
		if(!pid){
			//child goes here
			printf("%s",args[0]);
			const char* path = getenv("PATH");
			execvp(args[0],args);
			perror("Error  occured in execution");	
			}else{//parent goes here
				wait(&childStatus);
				printf("child process terminated \n");
				continue;
				}	

}
 
   return(0);
}
