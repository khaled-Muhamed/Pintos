#ifndef MATRIX_READ_H   /* Include guard */
#define MATRIX_READ_H

typedef int bool;
#define true 1
#define false 0

typedef struct size{
	int  row;
	int  column;
}size;

/* 
	- This method is responsible for reading content of matrix using file name.
*/
int ** read_matrix(char* file_name ,int** matrix_name); 

struct size* get_size(char* first_line,struct size* array_size);

bool is_num (int c);

int get_value(char* number);


char* append ( char* dest ,char* value);

int** define_2d_array(struct size* array_size,int** matrix_name);
void addLine_to_matrix(char* line, int** matrix_name,int row_index);
void print_matrix(int** matrix_name);
#endif // MATRIX_READ_H
