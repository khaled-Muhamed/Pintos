#ifndef COMMAND_PARSER_H   /* Include guard */
#define COMMAND_PARSER_H
typedef int bool;
#define true 1
#define false 0

/* 
	- This function should be responsible for importing all details of the command 
	- Should specify the type of the command "comment, cd, echo, expression - X=5 -, else"
	- Should specify the arguments of the command
	- Should specify if the command is background or foreground
	- Should consider all parsing special cases, example: many spaces in  "ls     -a"

	- You're left free to decide how to return your imported details of this command

	- Best practice is to use helper function for each collection of logical instructions,
	  example: function for splitting the command by space into array of strings, ..etc
*/
void parse_command(const char* commandLine);
int getNumberOfArgs( char* delim , const char* string ,char* flag);
bool check_delim(int i , const char* string,char* flag);	
char* copy_command(char* dist , const char* src );
void define_array(int num_of_args,char* flag);
void split_into_args(const char* string, char* flag);
void add_to_args(int location_in_args,char* str);
void print_args ();
void copy (char* dest,const char* src,int start,int end);

#endif // COMMAND_PARSER_H
