#include "matrix_read.h"
#include <math.h>
#include <ctype.h>

int** read_matrix(char* file_name ,int** matrix_name){
	 /* should check that argc > 1 */
	struct size* array_size =  malloc(sizeof(struct size*));
    FILE* file;
    if(file = fopen(file_name, "r")){; /* should check the result */
    char line[1000];
    bool size_line = true;int row_index=0;
    while (fgets(line, sizeof(line), file)) {	
	         line[strlen(line)- 1 ]='\0';
	         if(size_line){get_size(line,array_size);matrix_name = define_2d_array(array_size,matrix_name);size_line=false;}
         else{
         		 addLine_to_matrix(line,matrix_name,row_index);row_index++;
         }
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
    fclose(file);
    extern int error;error=0;
    return matrix_name;
}
else{
	printf("files don't exist\n");
	extern int  error;error = 1;
}
}

struct size* get_size(char* first_line,struct size* array_size){
	array_size->row = 0;
	array_size->column = 0;
    char arr[2];arr[1]='\0';
    char* number = (char*)malloc(sizeof(char));number[0]='\0';

    for(int i = 0 ; i < strlen(first_line) ; i++) {			    
		if( isdigit(first_line[i])	 ){//number indicator
			     while( isdigit(first_line[i] ) ) 
				 	{arr[0] = first_line[i];number = append(number,arr);i++;}
				  if(array_size->row == 0){  
				  array_size->row = get_value(number);
				  }else if(array_size->column == 0){
				  array_size->column = get_value(number);}
				  number[0]='\0';	
						          }
    }
	return array_size;

}

int get_value(char* number){
	int value = 0;
	int i = 0;
	while( number[i] != '\0' ) {
		int power = strlen(number) - i - 1;
		value+= (number[i] - '0') * pow(10,power);i++;

	}
	return value;
}
char* append ( char* dest ,char* value){
    int start = (int)strlen(dest);
    dest = (char* ) realloc (dest, sizeof(char)* (int)strlen(dest) + (int)strlen(value) + 1  );
    int i = 0;
    while ( i < strlen(value) ){
        dest[start] = value[i] ;start++;i++;}
    dest[start] = '\0';
return dest;
}

bool is_num (int c){

if(c > '0' &&  c < '9') return true;
return false;
}


int** define_2d_array(struct size* array_size,int** matrix_name){
  	matrix_name = (int**) malloc(sizeof(int*) * (array_size->row + 1));	
  	matrix_name[array_size->row] = NULL;
  	int i=0;
	while(i < array_size->row ){
		matrix_name[i] = malloc(sizeof(int) * (array_size->column + 1) );
		matrix_name[i][array_size->column]='\0';
		i++;
	}
return matrix_name;	
}

void addLine_to_matrix(char* line, int** matrix_name,int row_index){
	bool negative =false,first=false;
	int i =0;
	int column_index=0;
	while( line[i] != '\0') {
		if(line[i]!='\t'){
			//number found
				int j = i,counter=0;
				while(line[j]!='\0' && line[j]!='\t' ){if(line[j]=='-'){negative=true;first=true;}j++;counter++;}
				int value=0;
				while(counter){if(negative==true && first==true){first=false;i++;counter--;}else{value+=(line[i] - '0')*pow(10,(counter-1));i++;counter--;}}
				if (negative == true) {value = -1 * value; negative=false;}
				matrix_name[row_index][column_index] = value;
				column_index++;
				}
				i++;
	}	
}

void print_matrix(int** matrix_name){
int i =0 ,j=0;
	while(matrix_name[i] != NULL ){
		j=0;
		while (matrix_name[i][j] != '\0'){
			printf("%d  ",matrix_name[i][j]);j++;
		}
		printf("\n");
		i++;

	}

}
