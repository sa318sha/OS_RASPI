#include <stdio.h>
extern char* test;

char func();
char func(){
    while(*test != '\0'){
        *test = '5';
        printf("hello %i", *test);
    }
    return '!';
}