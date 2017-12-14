#ifndef VARIABLES_H_   /* Include guard */
#define VARIABLES_H_

/* 
	- This function should be responsible for getting the value of a variable
	- To execute commands, You must always search for the executable files 
	  in the value returned by lookup_variable("PATH");
	- Your code must be dynamic and can handle any number of variables, However,
	  performance is not an issue since in practice we expect low number of variables
	  as a tip: simple array lookup would be fine
*/
struct variable lookup_variable( char* key );  

/*
	- This function should be responsible for setting the value of a variable
*/
void set_variable(  char* key ,  char* value );

void cpyStr ( char* dist ,  char* src);

char* cpystr_with_index(int start,int end,char* dest,char* src);

void define_last_cell_null(int sizeOfTable);

void copy_key(int sizeOfTable, char* key);

void copy_value(int sizeOfTable, char* value);

int get_table_length(struct variable* variabels);

void intialize_table();

void print_variables();
/* this method is used to check if user enters a variable in his command*/
int is_variable(char* input);
void split_and_set_variable(int index_of_equalSign, char* input);

void update_value( char* key , char* value );	
  
#endif // VARIABLES_H_
