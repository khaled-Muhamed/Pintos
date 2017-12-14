
bool crteate_child_execute_command(char** args){
	 int pid,childStatus;

	if ( strcmp(args[0] , "exit") != 0)	
 	 {pid = fork();
	  if(!pid){
		//child goes here
		if( background() ){args[ getLength2dArray(args) - 1 ] = NULL; }
		  execute();
		}else{
		//parent goes here
		  if( !background() ){ 
		     wait(&childStatus);
		     printf("child terminated parent was waiting\n");}

		  return false;}
	}else return true;
}

void execute(){
	int i = 0;
	while(pathValues[i] != NULL){execv(pathValues[i] ,args);i++;}
	perror("Error  occured in execution PATH variable error");
}

bool background(){
     if(strcmp (args[ getLength2dArray(args) - 1 ] , "&") == 0 ) return true;
 return false; 
}
