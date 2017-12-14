char pathDelimiters[2] = {':','\0'};
char cmdDelimiters[3] = {' ','\t','\0'};
struct variable* variables;
char ** args;
char** fileCommands;
char** pathValues;
char* input;
struct variable null_variable;
int count = 0;	


