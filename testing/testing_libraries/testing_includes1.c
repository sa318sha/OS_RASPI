#include <stdio.h>
#include "test_includes1.h"
#include "test_includes2.h"
int main(){
    printf("hello c world");
    int result = some_method();
    printf("%d",result);
}