#ifndef THREADS_CREATION_METHOD2_H   /* Include guard */
#define THREADS_CREATION_METHOD2_H


 struct matrix_runner_struct_method2
  {
  	int* rowA;
  	int* colB;
  	int answer;
  	int row_length;
  };

void thread_create_method2(int** matrixA,int** matrixB,pthread_t* tids,struct matrix_runner_struct_method2* thread_data_method2 ); 

void wait_threads_method2(char* output_file_name_method2,int number_of_threads, pthread_t* tids,struct matrix_runner_struct_method2* thread_data_method2);

int get_matrixA_rowLength_method2(int** matrixA);

void* matrix_runner_method2(void* arg);

int* cpyValue_withReturn( int* dest, int* src);

int* append_number(int* dest ,int value);

void type_data_to_file_method2(int* src,char* fileName);
#endif // THREADS_CREATION_METHOD2_H
