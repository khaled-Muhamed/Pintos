#include <string.h>
#include <stdlib.h>
void setup_environment( void )
{
	//first intialize table with 1 cell that carry nulls in order to 
	//avoid segmentation error.
		
	intialize_table();	
	//save PATH in table.
	set_variable( "PATH" , getenv("PATH") );	
	//define home
	set_variable( "HOME" , getenv("HOME") );
	//define home
	set_variable( "~" , getenv("HOME") );
	//define current working directory	
	set_variable( "PWD", getenv("PWD")  );
	//define null variable in order to return it 
	//when not find required variable
	null_variable.value = NULL;
	null_variable.value = NULL;		
}

void intialize_table(  ){
	variables = (struct variable* ) malloc (sizeof(struct  variable));
	variables[0].key = NULL;
	variables[0].value = NULL;
}	

