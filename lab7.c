#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int asize = 100, count = 0;

    // printf("Enter size: ");
    // scanf("%d", &asize);

    char* arr = (char*) malloc(sizeof(char) * asize);

    fgets(arr, asize, stdin);

    //arr = (char*)realloc(strlen(arr));
    // for (int i = 0; i < asize; i++) {
    //     if (strtok(arr, " ") == 3){
    //         k++;
    //     }
    // }
    arr = strtok(arr," ,.");
    while(arr){
        count++;
        
        //printf("size word %i: %i\n", count, strlen(arr));
        if (strlen(arr) == 3){
            printf("%s ", arr);
        }
        arr = strtok(NULL," ,.");

    }
    free(arr);
    
    return 0;
}