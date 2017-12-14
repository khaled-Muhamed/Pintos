#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0
void parse_value(char* value);
int size();
void print();
void add_to_pathValues(int location,char* str);
int getNumberOfArgs( char* delim ,const char* commandLine );

void cpyStr ( char* dist ,  char* src);
bool check_delim(int i , const char* commandLine);
char** pathValues;
char pathDelimiters[2];

int main () {
	pathDelimiters[0] =':';
	pathDelimiters[1] ='\0'; 
	int size = getNumberOfArgs( pathDelimiters,getenv("PATH"));
	pathValues =(char**) malloc (sizeof(char*) * (size+ 1 ) );
	int i =0;	
	for (i = 0; i < size ; i++){
		pathValues[i] = (char *) malloc(100 * sizeof(char));
		}
		/*last string is null*/
	pathValues[size] = NULL;
	char* path = getenv("PATH");
	printf("path values =%s\n",path);	
	parse_value(path);
	print();
						
 return 0;	
}

int getNumberOfArgs( char* delim ,const char* commandLine ){
/* -In this method we count number of arguments.*/
//argSize to count number of parameters sent in command.
	int argSize = 0,i = 0;
	bool aToZ = false;	
	while ( i < strlen(commandLine) )
		{			
			if (check_delim(i,commandLine)){
				aToZ = false;
			}else if (aToZ == false) {
				aToZ = true;
				argSize++;}
		i++;}
	printf("arguments size = %d\n",argSize);
return argSize;
}

bool check_delim(int i , const char* commandLine){
	int iterator = 0;
	if( pathDelimiters[iterator] != '\0'){ 
		if(commandLine[i] ==  pathDelimiters[iterator]) return true;
		else{iterator++;}
}return false;
}
void parse_value(char* commandLine){
	/*	
	-This methd is used to prepare argList 
	that will be sent to execute instruction
	-first of all you need to get number of arguments sent in command 
	to define array with that size.
	-then you will loop again in command to put it in argList.
	-finally return your argList.
	*/
	char* temp = malloc (50 * sizeof(char));
	memset(temp,'\0',50);
	/*location_in _args is an iterator to know where position of 
	command will be sent to add method*/
	int i=0,j = 0, location_in_args = 0,size=0;
	printf("length 0f commandLine=%d\n",(int)strlen(commandLine));
	while ( i < strlen(commandLine) )
	{					
		if ( commandLine[i] != ':')
		{	
		  temp[j] = commandLine[i];		  
		  j++;
		printf("temp now =%s\n",temp);		
		}else{
		if(j != 0){
			temp [j] = '\0';
			temp =  realloc(temp,sizeof(char) * (int)strlen(temp));	
			add_to_pathValues(location_in_args,temp);
			location_in_args++;
			size++;
			printf("put temp =%s\n",temp);			
			temp = (char* ) realloc(temp,sizeof(char) * 50);
			memset(temp,'\0',50);		
			j = 0;
			}		
		}i++;
		//check the case that it ends the string but temp has the last string	
	}
	//*we still have case that temp carry the last string and still not sent*/
	if ( strlen(temp) > 1  ||  ( (strlen(temp) == 1) && (strcmp(temp,"&") == 0) ) )	{
	 	add_to_pathValues(location_in_args,temp);}

pathValues = (char**) realloc(pathValues,sizeof(char*) * (size + 1));
pathValues[size] = NULL;	
free(temp);

} 
void add_to_pathValues(int location,char* str){
		int i = 0 ;	
	while ( i < strlen(str) ){
		pathValues[location][i] = str[i];
		i++;
	}
	pathValues[location][i] = '\0'; 
}

void print(){
		int i = 0;
	while(pathValues[i] != NULL) {printf("values[%d] =%s\n",i,pathValues[i]);i++;}

}
int size(){
		int size = 0;
	while(pathValues[size] != NULL) {size++;}
return size;
}

