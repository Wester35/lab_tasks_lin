#include <stdlib.h>
#include <stdio.h>
#include "my_lib.h"

int main(){

    void* (*my_sum_ptr)(void*, void*) = sum;
    int a = 2, b = 3;
    int* sum_result = my_sum_ptr(&a, &b);

    my_sum_ptr = divis;
    float c = 2, d = 3;
    float* divis_result = my_sum_ptr(&c, &d);

    printf("%d\t", *sum_result);
    printf("%f\t", *divis_result);

    return 0;
}