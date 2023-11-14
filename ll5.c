#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr_size, indx = 0;

    srand(time(NULL));

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    if (arr_size < 1) {
        printf("Invalid Value!\n");
        return 1;
    }

    int* arr = (int*)malloc(sizeof(int) * arr_size);

    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % 21 - 10;

    printf("Array:\n");
    for (int i = 0; i < arr_size; i++)
        printf("%4d", arr[i]);

    int* new_arr = NULL;
    printf("\nFinal array:\n");

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] >= 0) {
            new_arr = (int*)realloc(new_arr, (indx + 1) * sizeof(int));
            new_arr[indx] = arr[i];
            printf("%4d", new_arr[indx]);
            indx++;
        }
    }

    free(arr);
    free(new_arr);

    return 0;
}
