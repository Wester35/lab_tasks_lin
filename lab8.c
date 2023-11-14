#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_input(int* arr, int arr_size, int index) {
    if (index < arr_size) {
        arr[index] = rand() % 5 - 1;
        rand_input(arr, arr_size, index + 1);
    }
}

void print_arr(int* arr, int arr_size, int index) {
    if (index < arr_size) {
        printf("%4d", arr[index]);
        print_arr(arr, arr_size, index + 1);
    }
}

int search_min_el(int* arr, int arr_size, int index, int min_el) {
    if (index < arr_size) {
        if (min_el > arr[index])
            min_el = arr[index];
        search_min_el(arr, arr_size, index + 1, min_el);
    }
    else
        return min_el;
}

int counting_min_el(int* arr, int arr_size, int index, int min_el, int res) {
    if (index < arr_size) {
        if (min_el == arr[index])
            res++;
        counting_min_el(arr, arr_size, index + 1, min_el, res);
    }
    else
        return res;
}


int main() {
    int arr_size, min_el;

    srand(time(NULL));

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    int* arr = (int*)malloc(sizeof(int) * arr_size);

    rand_input(arr, arr_size, 0);
    print_arr(arr, arr_size, 0);
    min_el = search_min_el(arr, arr_size, 0, arr[0]);
    printf("\nThe number of min in the array is equal to %d \n",
           counting_min_el(arr, arr_size, 0, min_el, 0));
    free(arr);

    return 0;
}