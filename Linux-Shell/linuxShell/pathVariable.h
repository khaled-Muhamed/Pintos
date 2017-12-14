#ifndef PATHVARIABLE_H_   /* Include guard */
#define PATHVARIABLE_H_

/* 
	-This methd is used to parse pathValues in order to split it
	   into values.
	- example: 
		pathValue =/usr/bin:/usr/local/bin
		it will be 
  		path1 =/usr/bin
		path2 =/usr/local/bin
	and so on.
*/

void parse_path_value(const char* pathValue);

/* this method is used to claculate actual path*/
void calc_path();
/*
  -This method take a string as input to be put in 
	pathValues array.
  -it is called through parsing path to split path variable 
   into cells.	
*/
void add_to_pathValues(int location,char* str);

/* -This method responsible for appending command to path
    for example (if command is ls):
	input = /usr/bin
	output = /usr/bin/ls
*/ 	

void append_command_to_path();

/* -This methd used to print paths exist in pathValues array.
   -It can be used for debugging purpose.		
*/
	
void print();  
#endif // COMMANDS_H_
