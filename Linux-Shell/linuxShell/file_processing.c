/* 
	history file section
*/
void write_to_history_file(int count,const char* commandLine)
{
	FILE *fp = get_history_file(count);
	if (!fp) {
	    printf("file can't be opened no history file or something wrong");
	}else{
	fprintf(fp,"%d	%s\n",count,commandLine);
	 close_history_file(fp);}

}

FILE* get_history_file(int count)
{
	
	if(count == 0)return fopen("history", "w");
return fopen("history", "a");
}

void close_history_file(FILE* fp){
fclose(fp);}

bool is_history(){
if (strcmp(args[0],"history") == 0)  return true;
return false; 
}

void print_history(){
	int c;
	FILE *file;
	file = fopen("history", "r");
	if (file) {
	    while ((c = getc(file)) != EOF)
		putchar(c);
	    fclose(file);
	}
}

/* 
	log file section
*/

void open_log_file()
{
	// you should implement this function
}

FILE* get_log_file()
{
	// you should implement this function
}

void close_log_file()
{
	// you should implement this function
}


/* 
	CommandsBatch file section
*/
FILE* open_commands_batch_file(const char* path )	
{
	FILE* file = fopen(path, "r");	
	if (file == NULL) {
       	 printf("Error: file pointer is null.");
        exit(1);}
	fileCommands = (char** )malloc( sizeof(char* ));
	fileCommands[0] = NULL;
	return file ;	
}

char** get_commands_from_batch_file(FILE* file)
{   
    char* lineBuffer = (char* )malloc( sizeof(char) * 100);	
    char ch = getc(file);
    	
   while( (ch != EOF)){
	int count = 0;
	 while ((ch != '\n') ) {
		lineBuffer[count] = ch;
		count++;
		ch = getc(file);	
	    }
	  	lineBuffer[count] = '\0';
		int numberOfCommands = getLength2dArray(fileCommands);
		fileCommands = realloc (fileCommands ,(numberOfCommands + 2) * sizeof(char *));
		fileCommands[ numberOfCommands] = (char *) malloc((strlen(lineBuffer) + 1) * sizeof(char));
		setValue(fileCommands[ numberOfCommands],lineBuffer); 
		fileCommands[ numberOfCommands + 1] = NULL;
		ch = getc(file);
		
			
	}
	 return fileCommands;
	 }

void close_commands_batch_file()
{
	// you should implement this function
}

void setValue(char* dist ,char* src)
{
	int i=0;
	while(i <= (int)strlen(src) ){
		dist[i] = src[i];	
		i++;	
	} 
}


int getLength2dArray( char** table )
{
    int count = 0;
    while ( table[count] != NULL ) count++;
return count;
}
