#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "threads_creation_method1.c"
#include "threads_creation_method2.c"
#include "matrix_read.c"

int** matrixA;
int** matrixB;
char* output_file1;
char* output_file2;
int error;

struct timeval stop, start;
bool read_files(int argc,char *argv[]);
int get_number_of_threads_method1();
void print(int** matrix);
void write_time_interval(char* output_file,int Seconds,int Microseconds,int threads_num);
int get_number_of_threads_method2();


int main(int argc, char *argv[])
{        
/**************************************************************************************************************
                                               reading  Files
                                              
****************************************************************************************************************/
    int file_error = read_files(argc,argv);
    if( !file_error ){

/**************************************************************************************************************
                                              method1 start here
                                              
****************************************************************************************************************/
   int number_of_row_threads_method1 = get_number_of_threads_method1();
/*start row threads*/
    pthread_t tids_method1 [number_of_row_threads_method1];
   //launch threads in method1.
     struct matrix_runner_struct_method1 threads_datum_method1[number_of_row_threads_method1];
  gettimeofday(&start, NULL);
    thread_create_method1(matrixA,matrixB,number_of_row_threads_method1,tids_method1,threads_datum_method1);
  //wait for all threads to finish
    wait_threads_method1(output_file1,number_of_row_threads_method1,tids_method1,threads_datum_method1);
  gettimeofday(&stop, NULL); //end checking time
  write_time_interval(output_file1,stop.tv_sec - start.tv_sec,stop.tv_usec - start.tv_usec,number_of_row_threads_method1);
 
  /**************************************************************************************************************
                                              method2 start here
                                              
  ****************************************************************************************************************/
   int number_of_row_threads_method2 = get_number_of_threads_method2();
 /*start row threads*/
     pthread_t tids_method2 [number_of_row_threads_method2];
    //launch threads in method2.
      struct matrix_runner_struct_method2 threads_datum_method2[number_of_row_threads_method2];
   gettimeofday(&start, NULL);
     thread_create_method2(matrixA,matrixB,tids_method2,threads_datum_method2);
   //wait for all threads to finish
     wait_threads_method2(output_file2,number_of_row_threads_method2,tids_method2,threads_datum_method2);
   gettimeofday(&stop, NULL); //end checking time
   write_time_interval(output_file2,stop.tv_sec - start.tv_sec,stop.tv_usec - start.tv_usec,number_of_row_threads_method2);
//   write_time_interval(output_file1,stop.tv_sec - start.tv_sec,stop.tv_usec - start.tv_usec,number_of_row_threads_method1);
    return 0;
  }
}


void write_time_interval(char* output_file,int Seconds,int Microseconds,int threads_num){
  FILE* fp = fopen (output_file, "a");
  fprintf(fp, "%s %d\n", "time interval in seconds =",Seconds);
  fprintf(fp, "%s %d\n", "time interval in Microseconds =",Microseconds);
  fprintf(fp, "%s %d\n", "number of threads =",threads_num);
  fclose(fp);

}

int get_number_of_threads_method1(){
int counter = 0;
  while(matrixA[counter] != NULL){counter++;}
return counter;
}

int  get_number_of_threads_method2(){
  int i=0 , rows =0 ,columns = 0;
  while(matrixA[i] != NULL){rows++;i++;}
  i = 0;
  while(matrixB[0][i] != '\0'){columns++;i++;}
return (rows * columns);
}

int read_files(int argc,char *argv[]){

if( argc == 3 ){
      matrixA = read_matrix(argv[1],matrixA);
      matrixB = read_matrix(argv[2],matrixB);
       output_file1 = "output1";
       output_file2 = "output2";
       if(error == 1){return 1;}
    }else if( argc == 4 ){
      matrixA = read_matrix(argv[1],matrixA);
      matrixB = read_matrix(argv[2],matrixB);
      output_file1 = argv[3];
      output_file2 = "output2.txt";
      if(error == 1){return 1;}
    }else if(argc == 1 ){
       matrixA = read_matrix("a.txt",matrixA);
       matrixB = read_matrix("b.txt",matrixB);
       output_file1 = "output1.txt";
       output_file2 = "output2.txt";
       if(error == 1){return 1;}
     }else if(argc == 5){
       matrixA = read_matrix("a.txt",matrixA);
       matrixB = read_matrix("b.txt",matrixB);
       output_file1 = argv[3];
       output_file2 = argv[4];
       if(error == 1){return 1;}
     }else{
      return 1;
     }

} 
 
