#include "threads_creation_method2.h"

void* matrix_runner_method2(void* arg){
 struct matrix_runner_struct_method2 *thread_struct = (struct matrix_runner_struct_method2*) arg;
  int  i = 0 ,sum = 0;
   while(i < thread_struct->row_length ){
      sum += (thread_struct->rowA[i] * thread_struct->colB[i]);i++;
    } thread_struct->answer = sum;
  pthread_exit(0);
}

void thread_create_method2(int ** matrixA,int ** matrixB,pthread_t* tids,struct matrix_runner_struct_method2* thread_data_method2 ){
int  i =0,j = 0,thread_index=0;
int * temp = malloc(sizeof(int )*2);temp[0] = '\0';
   while(matrixA[i]!= NULL ){
      j = 0;
      while(matrixB[0][j]!= '\0' ){
      	//get row from matrixA
        thread_data_method2[thread_index].rowA = matrixA[i];
        int  k=0;//get column from matrixB
        while(matrixB[k]!= NULL){temp = append_number(temp,matrixB[k][j]);k++;}
         thread_data_method2[thread_index].colB = cpyValue_withReturn ( thread_data_method2[thread_index].colB, temp);
         //set temp all null to use it next loop.
        temp[0] = '\0';
        thread_data_method2[thread_index].row_length = get_matrixA_rowLength_method2(matrixA);
        pthread_attr_t attr;pthread_attr_init(&attr);
        pthread_create(&tids[thread_index],&attr,matrix_runner_method2,&thread_data_method2[thread_index]);
        thread_index++;j++;
    }
    i++;
  }
  free(temp);
}


int  get_matrixA_rowLength_method2(int ** matrixA){
  int  column=0;
  while(matrixA[0][column] != '\0'){column++;}
  return column;
}

 void wait_threads_method2(char* output_file_name_method2,int number_of_threads, pthread_t* tids,struct matrix_runner_struct_method2* thread_data_method2){
  //  type_data_to_file(threada_data[i].answer,output_file_name);
    int * temp = malloc(sizeof(int )*(number_of_threads+1));temp[number_of_threads] = '\0';
    int  i = 0;
    for (i = 0; i < number_of_threads; i++){
    pthread_join(tids[i],NULL);
    temp[i] = thread_data_method2[i].answer;
    //type_data_to_file_method1(number_of_row_threads,threada_data[i].answer,output_file_name);
  } temp[i] ='\0';
  type_data_to_file_method2(temp,output_file_name_method2);
}

int * cpyValue_withReturn ( int * dest, int * src){
  int  length = 0;
  while(src[length]!='\0')length++;
  dest =(int *) malloc(sizeof(int )*(length+1));int  i=0;
  while( src[i]!='\0') {dest[i] = src[i];i++;}
  dest[i]='\0';
return dest;
}

int* append_number(int* dest ,int value){
    int start = 0;
    while(dest[start] != '\0') start++;
    dest = (int * ) realloc (dest, sizeof(int )* (start + 2) );
    dest[start] = value ;dest[start + 1] = '\0';
return dest;
}

void type_data_to_file_method2(int* src,char* fileName){
  FILE * fp; fp = fopen (fileName, "w");
  extern int** matrixA;extern int** matrixB;
  int  i = 0,j=0,index=0;
  while(matrixA[i] != NULL){
    while(matrixB[0][j] != '\0'){
        fprintf(fp, "%d%c", src[index],'\t');index++;j++;
    }
     fprintf(fp, "\n");i++;j=0;
  }
  fclose(fp);
  
  
}