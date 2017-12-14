#ifndef COMMANDS_H_   /* Include guard */
#define COMMANDS_H_

/* 
	- This function should be responsible for implementing the "cd" shell command
*/
void cd(  char* path );  

/* 
	- This function should be responsible for implementing the "echo" shell command
	- Typically should lookup any variable included in the message
*/
void echo(  char* message );
/* -this method is used to prepare message sent 
	through echo commands*/
void prepare_message();
/* - This method is used to realloc args because after
        we use args in echo command we got args cells 
	empty so we need to reallocate it.	
*/
void realloc_args();
/* -This method is used t check if it was echo 
	command*/
bool check_echo();
/* -This method responsible for intializing meeaage variable
	and setting it's value*/
void find_null (char* com); 
/* -this method will replace variables with it's content in varTable*/ 
void subistitute_variables(char* mes);
void append_to_message(char* fullMessage,char* value);
bool is_underScore(char character) ;
bool is_char(char character);
bool is_num(char character);

#endif // COMMANDS_H_
