#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>


#include "command_parser.h"
#include "file_processing.h"
#include "externVars.h"
#include "variables.h"
#include "environment.h"
#include "pathVariable.h"
#include "command_executer.h"
#include "commands.h"
#include "inputModify.h"

#include "command_parser.c"
#include "command_executer.c"
#include "file_processing.c"
#include "variables.c"
#include "environment.c"
#include "pathVariable.c"
#include "commands.c"
#include "inputModify.c"


void start_shell(bool read_from_file);
void shell_loop(bool input_from_file);
bool take_user_input();
void print_shell(void);

int main(int argc, char *argv[])
{	
	//// any early configuration should be here

    setup_environment();	    
    if( argc > 1 ){
	set_variable("filePath",argv[1]);
        start_shell(true);
    }
    else{
        start_shell(false);
    }

    return 0;
}

void start_shell(bool read_from_file)
{
	//cd(getenv("HOME")); // let	 shell starts from home

	if(read_from_file){
		// file processing functions should be called from here
		shell_loop(true);
	}
	else{
		shell_loop(false);
	}
}

void shell_loop(bool input_from_file)
{
	bool from_file = input_from_file;
	bool exit = false;

	while(true){
		if(from_file){
			FILE* file = open_commands_batch_file(lookup_variable("filePath").value);
			fileCommands = get_commands_from_batch_file(file);	
			int i = 0;
			while(fileCommands[i] != NULL){
				input = malloc( sizeof(char) * strlen(fileCommands[i]));
				strcpy(input,fileCommands[i]);
				write_to_history_file( count ,fileCommands[i]);
				count++;
				parse_command(input);
				if( check_echo() ){prepare_message();}
				else if(check_cd()){ prepare_path();}
				else if(is_history()){ print_history();i++;}
				else{ 			
				parse_path_value((const char*)lookup_variable("PATH").value);
				calc_path();exit = crteate_child_execute_command(args);
				if ( exit == true )break;
				else{i++;continue;}
				   }		
				}//we finished file so break
			break;		
		}else{	
					
			print_shell();
			if(!take_user_input()) continue;			
			input = sub_variables (input);
			write_to_history_file( count ,input);count++;
			if(!is_variable(input))
			{	parse_command(input);
				if( check_echo() ){prepare_message();}
				else if(check_cd()){ prepare_path();}
				else if(is_history()){ print_history();}
				else{ 			
				parse_path_value((const char*)lookup_variable("PATH").value);
				calc_path();exit = crteate_child_execute_command(args);
				if ( exit == true ) {break;}
				else{continue;}
				   }
			  }
				
		}
	}
}
/* this will print shell> in interactive mode*/
void print_shell(void){
	fprintf(stdout,"SHELL>>");
}
bool take_user_input(){
	char command[100];	
 	fgets (command, 100, stdin);
          /* Remove trailing newline, if there. */ 
     	if ((strlen(command) > 0) && (command[strlen (command) - 1] == '\n')){
	     command[strlen (command) - 1] = '\0';}
	if((strlen(command) == 0)) return false;
	input = malloc( sizeof(char) * (strlen(command)+1));strcpy(input,command);
return true;
}
