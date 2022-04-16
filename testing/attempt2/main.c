#include "stdio.h"

// int test(int a, int b);
int add(int a,int b);
extern char hello_string[];
int main(){
    // printf("hello world\n %i", TEMP);
    // int temp = test(2,3);
    // printf("hello world")
    // hello[3] = '1';
    // char *ptr = hello;
    // while(*ptr != '\0'){
    //     printf("%i", *ptr);
    // }
    char *ptr = hello_string;
    while(*ptr != '\0'){
        
        printf("%c",*ptr);
        *ptr += 10;
        ptr++;
    
    }
    
    
    printf("\n");
    int result = add(3,4);
    return result+5;
}