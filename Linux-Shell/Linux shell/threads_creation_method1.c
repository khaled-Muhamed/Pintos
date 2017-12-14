#include "threads_creation_method1.h"

void* matrix_runner_method1(void* arg){

	struct matrix_runner_struct_method1 *thread_struct = (struct matrix_runner_struct_method1*) arg;
	thread_struct->answer =malloc(sizeof(int));thread_struct->answer[0]='\0';
	int k =0,index=0,sum=0,size=0;
	int i = 0,j=0;
	while( thread_struct->matrixB[0][i] !='\0' ){
		k=0;sum=0,j=0;
		while(thread_struct->matrixB[j] != NULL) {
			sum +=  thread_struct->rowA[k] * thread_struct->matrixB[k][i];
			k++;j++;
		}
		thread_struct->answer =realloc(thread_struct->answer,(size + 2) *(sizeof(int)) );size++;
		thread_struct->answer [index] = sum;
		thread_struct->answer [index + 1] = '\0';
		index++;i++;
	} 
	pthread_exit(0);
}

void thread_create_method1(int** matrixA,int** matrixB,int number_of_threads,pthread_t* tids,struct matrix_runner_struct_method1* thread_data){
int i =0 ;
   while(i < number_of_threads ){
 		thread_data[i].rowA = matrixA[i];
 		int k=0;
 		thread_data[i].matrixB = matrixB;
 	 	thread_data[i].row_length = get_matrixA_rowLength_method1	(matrixA);
 	 	pthread_attr_t attr;
 		pthread_attr_init(&attr);
 		pthread_create(&tids[i],&attr,matrix_runner_method1,&thread_data[i]);
 		i++;
 	}
}
int get_matrixA_rowLength_method1(int** matrixA){
	int column=0;
	while(matrixA[0][column] != '\0'){column++;}
	return column;
}
 void wait_threads_method1( char* output_file_name, int number_of_row_threads, pthread_t* tids , struct matrix_runner_struct_method1* thread_data){
	 	for (int i = 0; i < number_of_row_threads; ++i){
 		pthread_join(tids[i],NULL);
 		int j=0;
 		type_data_to_file_method1(i,thread_data[i].answer,output_file_name);
 	}
}

void cpyValue ( int * dest, int* src){
	int  length = 0;
	while(src[length]!='\0')length++;
	dest =(int *) malloc(sizeof(int )*(length+1));int  i=0;
	while( src[i]!='\0') {dest[i] = src[i];i++;}
	dest[i]='\0';

}

void type_data_to_file_method1(int  indicator,int * src,char* fileName){
	FILE * fp;
	if(indicator == 0 ){fp = fopen (fileName, "w");}
	else{fp = fopen (fileName, "a");}
	int  i = 0;
	while( src[i]!='\0') {fprintf(fp, "%d%c", src[i],'\t');i++;}
	fprintf(fp, "\n");
	fclose(fp);
	
}
