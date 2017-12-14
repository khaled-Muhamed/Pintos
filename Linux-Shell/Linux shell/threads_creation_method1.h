#ifndef THREADS_CREATION_METHOD1_H   /* Include guard */
#define THREADS_CREATION_METHOD1_H


 struct matrix_runner_struct_method1
  {
  	int * rowA;
  	int ** matrixB;
  	int * answer;
  	int  row_length;
  };

void thread_create_method1(int ** matrixA,int ** matrixB,int  number_of_threads,pthread_t* tids,struct matrix_runner_struct_method1* thread_data); 

void wait_threads_method1( char* output_file_name, int  number_of_row_threads, pthread_t* tids , struct matrix_runner_struct_method1* threada_data);

int  get_matrixA_rowLength_method1(int ** matrixA);

void* matrix_runner_method1(void* arg);

void cpyValue ( int * dest, int * src);

void type_data_to_file_method1(int  indicator,int * src,char* fileName);

#endif // THREADS_CREATION_METHOD1_H
