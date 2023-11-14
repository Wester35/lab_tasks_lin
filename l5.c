#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main() {
    int arr_size, new_arr_size = 0, indx = 0;

    srand(time(NULL));

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    if (arr_size < 1) {
        printf("Invalid Value!");
        return 1;
    }

    int* arr = (int*)malloc(sizeof(int) * arr_size);

    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % 21 - 10;

    for (int i = 0; i < arr_size; i++)
        printf("%4d", arr[i]);
    int* new_arr;
    for (int i = 0; i < arr_size; i++)
        if (arr[i] >= 0){
            new_arr_size++;
            new_arr = (int*)realloc(arr, new_arr_size * sizeof(int));
            new_arr[indx] = arr[i];
            printf("%4d", new_arr[i]);
            indx++;
            
        }
    free(arr);
    // if (new_arr_size < 2) {
    //     printf("There is no sequence with less than two numbers\n");
    //     free(arr);
    //     return 0;
    // }


    
    //new_arr_size = arr_size;    

    // for (int i = 0; i < arr_size; i++)
    //     if (arr[i] >= 0 && indx < new_arr_size) {
    //         new_arr[indx] = arr[i];
    //         indx++;
    //     }
    //     else
    //         continue;

    

    //free(arr);
    printf("\nFinal array:\n");

    // for (int i = 0; i < new_arr_size; i++)
    //     printf("%4d", new_arr[i]);

    //free(new_arr);

    return 0;
}