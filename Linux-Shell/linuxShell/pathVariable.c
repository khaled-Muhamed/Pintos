#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
	
void parse_path_value( const char* pathValue){
	int size = getNumberOfArgs(pathDelimiters ,pathValue ,"path");
	pathValues = (char**) malloc(sizeof(char*) * (size + 1));
	define_array( size,"pathValues");
	split_into_args(pathValue,"path");	
	}
 
void add_to_pathValues(int location,char* str){
	int i = 0 ;	
	while ( i < strlen(str) ){pathValues[location][i] = str[i];i++;
	}pathValues[location][i] = '\0'; 
}

void print_path_values(){
	int i = 0;
	while(pathValues[i] != NULL) {printf("values[%d] =%sand size=%d\n",i,pathValues[i],(int)strlen(pathValues[i]));i++;}

}

void calc_path(){
	append_command_to_path();
}
 
void append_command_to_path(){
	int iterator = 0;
	while ( pathValues[iterator] != NULL )
	{
	 int i = 0,start = (int)strlen(pathValues[iterator]),size = ((int)strlen(pathValues[iterator]) + (int) strlen(args[0]) + 2);
	 pathValues[iterator] = (char*)realloc(pathValues[iterator] , sizeof(char)*size);
	 pathValues[iterator][start] ='/';
		for(i = 0 ; i < ((int) strlen(args[0]) + 1) ;i++)
			{pathValues[iterator][i + start + 1] =args[0][i];} 
	pathValues[iterator][i+start] ='\0';
	iterator++;	
	}		

}

