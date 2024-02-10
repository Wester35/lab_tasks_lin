//
// Created by wester on 10.02.24.
//

#include "my_lib.h"
#include <stdlib.h>
void* sum(void* a, void* b) {
    int *_a = a;
    int *_b = b;
    int* result = malloc(sizeof(int));
    *result = *_a + *_b;
    return result;
}

void* divis(void* a, void* b) {
    float *_a = a;
    float *_b = b;
    if(*_b == 0){
        printf("Делить на 0 нельзя!\n");
        return 0;
    }
    float* result = malloc(sizeof(float));
    *result = *_a / *_b;
    return result;
}