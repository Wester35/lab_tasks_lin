#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void replace_max_with_min(int* arr, int size) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == max) {
            arr[i] = min;
        }
    }
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    clock_t start = clock();

    int size = 100;

    int arr[size];


    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1; 
    }



    printf("Исходный массив: ");
    print_array(arr, size);


    replace_max_with_min(arr, size);


    printf("Изменённый массив: ");
    print_array(arr, size);


    clock_t end = clock();


    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения программы: %.6f секунд\n", time_taken);

    return 0;
}
