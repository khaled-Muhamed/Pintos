#include<string.h>
#include<stdlib.h>
#include<stdio.h>
char* sub_variables (char* input){
    int i = 0;
    char* full_input = (char*)malloc(sizeof(char) * (strlen(input) + 1));full_input[strlen(input)]='\0';
    memset(full_input,'\0',strlen(input));
    char arr[2];arr[1]='\0';
    char* temp = (char*)malloc(sizeof(char));temp[0]='\0';
    while ( input[i] != '\0') {
        if( input[i] =='$'){//character indicator
                    i++;
                    while(is_num(input[i]) || is_char(input[i]) || is_underScore(input[i]) )
                        {arr[0] = input[i];temp = append(temp,arr);i++;}
                   char* value = get_value(temp);full_input = append(full_input,value);
		   temp[0]='\0';	
             }else{
            arr[0] = input[i];full_input = append(full_input,arr);i++;
        }
    }
	return full_input;

}
char* get_value(char* key){
    return lookup_variable(key).value;
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
