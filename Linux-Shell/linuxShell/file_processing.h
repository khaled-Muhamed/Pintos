#ifndef FILE_PROCESSING_H_   /* Include guard */
#define FILE_PROCESSING_H_

/* 
	history file basic functions' prototypes
*/
void write_to_history_file(int count ,const char* commandLine);
FILE* get_history_file(int count);
void close_history_file(FILE* fp);
void print_history();
bool is_history();

/* 
	log file basic functions' prototypes
*/
void open_log_file();
/* -This method is responsible for creating file ifn't exist
   -if already exist it return a pointer t the file*/
FILE* get_log_file();
void close_log_file();

/* 
	CommandsBatch file basic functions' prototypes
*/
FILE* open_commands_batch_file(const char* path );
char** get_commands_from_batch_file(FILE* file);
void close_commands_batch_file();
int getLength2dArray( char** table );
void setValue(char* dist ,char* src);

#endif // FILE_PROCESSING_H_
