#include <string.h>
typedef int bool;
#define true 1
#define false 0
void parse_command(const char* commandLine){
	args = (char**)malloc(sizeof(char*));args[0] = (char *) malloc(100 * sizeof(char));args[0] = NULL;	
	define_array(getNumberOfArgs(cmdDelimiters,commandLine,"command"),"args");split_into_args(commandLine,"command");
}

void print_args (){
	int i =0;printf("args_size = %d\n",getLength2dArray(args));
	while (args[i] != NULL){printf("args[%d] =%s and of size =%d\n",i,args[i],(int)strlen(args[i]));i++;	}
}

int getNumberOfArgs( char* delim , const char* string ,char* flag){
	int argSize = 0,i = 0,strlength =strlen(string) ;bool aToZ = false; 	
	while ( i < strlength ){
	    if (check_delim(i,string,flag)){aToZ = false;
	    }else if (aToZ == false) {aToZ = true;argSize++;}
	                     i++;}return argSize;
}

void define_array(int num_of_args,char* flag){
	int i = 0;
	if(strcmp(flag,"args") == 0 ){args = (char **) realloc (args, (num_of_args + 1) * sizeof(char *));
		/* now you must define size of each string as a max size for each*/		
		for (i = 0; i <= (num_of_args) ; i++){args[i] = (char *) malloc(100 * sizeof(char));}
		/*last string is null*/
	args[i-1] = NULL;
 	}else if (strcmp(flag,"pathValues") == 0){while(i < num_of_args){ pathValues[i] = malloc( sizeof(char) * 100 );i++;}
		pathValues[num_of_args] = NULL;}			 			
}

void split_into_args(const char* string,char* flag){

	char* temp = malloc (50 * sizeof(char));
	memset(temp,'\0',50);
	int i=0,j = 0, location = 0;
	while ( i < strlen(string) )
	{ if ( !check_delim(i , string, flag) ){	
		  temp[j] = string[i];j++;		
	   }else{
		if(j != 0){temp [j] = '\0';temp =  realloc(temp,sizeof(char) * (int)strlen(temp));	
		  if(strcmp(flag,"command") == 0){
		    add_to_args(location,temp);
		    }else if(strcmp(flag,"path") == 0) {add_to_pathValues(location, temp);}
		    location++;	temp = (char* ) realloc(temp,sizeof(char) * 50);memset(temp,'\0',50);j = 0;}	
	        }i++;
	}
	//*we still have case that temp carry the last string and still not sent*/
	if ( strlen(temp) > 0  ||  ( (strlen(temp) == 1) && (strcmp(temp,"&") == 0) ) )	{
	 	if(strcmp(flag,"command") == 0){
			add_to_args(location,temp);
		}else if(strcmp(flag,"path") == 0) {
			add_to_pathValues(location, temp);
		    		}
		}
	free(temp);
}

bool check_delim(int i , const char* string,char* flag){
	int iterator = 0;
	if(strcmp(flag,"path") == 0 ){
		while(pathDelimiters[iterator] != '\0'){	
			if(string[i] ==  pathDelimiters[iterator]) return true;
			else{iterator++;}
		}
	}else if(strcmp (flag,"command") == 0 ){
		//we need to handle case that command in an echo command
		//so we need the string as it is without parsing.
		if( args[0] != NULL && strcmp(args[0] ,"echo")==0 ) {return false;}	
		while(cmdDelimiters[iterator] != '\0'){ 	
			if(string[i] ==  cmdDelimiters[iterator]) {return true;}
			else{iterator++;}
		}	
}
return false;
}

void add_to_args(int location_in_args,char* str){
	int i = 0 ;	
	while ( i < strlen(str) ){
		args[location_in_args][i] = str[i];
		i++;
	}
	args[location_in_args][i] = '\0'; 
}

