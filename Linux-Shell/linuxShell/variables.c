#include <stdlib.h>
#include <string.h>

typedef struct variable{
	char* key;
	char* value;
}variable;

	
struct variable lookup_variable(  char* key )
{
  int i=0;
	while (variables[i].key != NULL ){
		if( strcmp(variables[i].key , key) == 0) {return variables[i];}
		i++;}
return null_variable;
}
	
	/*
	-a struct created for each (key,value).	
	-don't forget last index must be a null in table.
	*/
void set_variable(  char* key ,  char* value )
{
  	int sizeOfTable = get_table_length(variables);
	if(sizeOfTable == 0) intialize_table();
	//we added 2 because we want additional cell be null.
	if(lookup_variable(key).value != NULL ){update_value( key , value );}
	else{
	variables = (struct variable* ) realloc (variables,(sizeOfTable + 2) * sizeof(struct  variable));
	define_last_cell_null(sizeOfTable + 1);copy_key(sizeOfTable,key);copy_value(sizeOfTable,value);
	}
}
void update_value( char* key , char* value ){
struct variable temp = lookup_variable(key);
	temp.value = (char*)	realloc(temp.value,sizeof(char) * (strlen(value)+1));
	cpyStr(temp.value,value);
}
void cpyStr ( char* dest, char* src){
	dest =(char*) realloc(dest,sizeof(char)*(strlen(src)+1));int i=0;
	while(i <strlen(src) ) {dest[i] = src[i];i++;}
	dest[i]='\0';
}


void define_last_cell_null(int sizeOfTable){	
	variables[sizeOfTable].key = NULL;
	variables[sizeOfTable].value = NULL; 
}


void copy_key(int sizeOfTable, char* key){	
	variables[sizeOfTable].key = malloc( sizeof(char) * (strlen(key)+1));
	cpyStr( variables[sizeOfTable].key , key );
	
}

void copy_value(int sizeOfTable, char* value){	
	variables[sizeOfTable].value = malloc( sizeof(char) * (strlen(value)+1));
	cpyStr( variables[sizeOfTable].value , value );
	
}

int get_table_length(struct variable* variabels){
	int size = 0,i = 0;	
	while ( variables[i].key != NULL ) {size++; i++;}
	return size;
}
  
void print_variables(){
	int i = 0;	
	while ( variables[i].key != NULL ) {
	printf("value[%d] =%s and key[%d] =%s\n",i,variables[i].value,i,variables[i].key);
	i++;	
	}
}

int is_variable(char* input){ 
	int i =0;
	while( input[i] != '\0'){if(input[i]=='='){split_and_set_variable(i,input);return i;}i++;}
return 0;
}

char* cpystr_with_index(int start,int end,char* dest,char* src){	
	int i =0,quotes=0;
	while ( start <  end ){if( src[start] != '"'){dest[i] = src[start];i++;}else{quotes++;}start++;}
	dest[i] = '\0';dest = (char*)realloc(dest,sizeof(char) * ( strlen(dest) - quotes) + 1 );
return dest;

}

void split_and_set_variable(int index_of_equalSign, char* input){
	char* key = (char*) malloc(sizeof(char) * ( index_of_equalSign + 1 ));
	cpystr_with_index(0,index_of_equalSign ,key, input);
	char* value = (char*) malloc(sizeof(char) * ( ( (int) strlen(input) ) - index_of_equalSign ) + 1);	
	cpystr_with_index(index_of_equalSign + 1,((int)strlen(input)),value,input);
	set_variable(key ,value);free(key);free(value);
	}
	
