#include <stdio.h>

int main()
{
    int num = 10;
    int* numPtr = &num;                 // pointer pointing to num's memory address

    printf("num:     %d\n", num);       // num value
    printf("&num:    %p \n", &num);     // num's memory address
    printf("numPtr:  %p\n", numPtr);    // numPtr's value = &num
    printf("*numPtr: %d \n", *numPtr);  // getting value from num's memory address
    
    // in resume, a pointer points to a variable's memory address
    // &varName --> return the memory address
    // *pointer --> return the value at that memory address

    return 0;
}