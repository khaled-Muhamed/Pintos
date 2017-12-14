#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void cd( char* path )
{	
    if( chdir(path) == 0 )              
    {
	printf(" i am here and having path =%s\n",path);
       //we have changed directory but pwd still unchanged so we have to change it also
       set_variable("PWD" , (char*)path );
    }else{
        printf("Error changing dir %s\n",strerror(errno));      
    }

}  

void echo( char* message ){
	printf("%s\n",message);
}


void prepare_message(){
  realloc_args();
  char* mes;int iterator = 1;
  int i = 0,index =0,size=0;while ( args[iterator] != NULL ){size+=strlen(args[iterator]);iterator++;}
  mes = (char*) malloc(sizeof(char) *(size+1) );memset(mes,'\0',size);mes[size]='\0';iterator=1;
  while ( args[iterator] != NULL ){
     for(i = 0 ; i < ((int) strlen(args[iterator])) ;i++){mes[index] =args[iterator][i];index++;} 
     iterator++;}
     echo(mes);
}

void prepare_path(){
  realloc_args();
  char* path;int iterator = 1;
  int i = 0,index =0,size=0;while ( args[iterator] != NULL ){size+=strlen(args[iterator]);iterator++;}
  path = (char*) malloc(sizeof(char) *(size+1) );memset(path,'\0',size);path[size]='\0';iterator=1;
  while ( args[iterator] != NULL ){
     for(i = 0 ; i < ((int) strlen(args[iterator])) ;i++){path[index] =args[iterator][i];index++;} 
     iterator++;}
     cd(path);
}

bool is_num(char character) {
	if( character >= '0' && character <= '9' ) return true;
return false;  
}

bool is_char(char character) {
	if( ( character >= 'a' && character <= 'z' )|| ( character > 'A' && character < 'Z' ) ) return true;
return false;  
}


bool is_underScore(char character) {
	if ( character == '_' ) return true;
return false;  
}
void realloc_args(){
	int counter=0;
	  while(args[counter] != NULL && strlen(args[counter]) != 0 ){counter++;}
	  args = (char**) realloc( args , sizeof(char*) * (counter+1) );
	  args[counter] = NULL;
}

bool check_echo(){
     if(strcmp(args[0],"echo")==0 ) return true;
 return false; 
}

bool check_cd(){
     if(strcmp(args[0],"cd")==0 ) return true;
 return false; 
}
