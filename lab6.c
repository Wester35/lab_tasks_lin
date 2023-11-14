#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Check_9(int digit) {
    if (digit % 9 == 0)
        printf("Yes\n");
    else
        printf("No\n");
}

void Rand_Input_Arr(int* arr, int array_size) {
    for (int i = 0; i < array_size; i++)
        arr[i] = rand() % 21 - 10;
}

void Rand_Input_Matrix(int size_m, int size_n, int arr[size_m][size_n]) {
    for (int i = 0; i < size_m; i++)
        for (int j = 0; j < size_n; j++)
            arr[i][j] = rand() % 7 - 1;
}

void Print_Array(int* arr, int array_size) {
    for (int i = 0; i < array_size; i++)
        printf("%4d", arr[i]);
}

void Print_Matrix(int row, int column, int matrix[row][column]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}

int Count_Min_Elem(int* arr, int array_size, int min_arr_elem, int indx) {
    for (int i = 1; i < array_size; i++)
        if (min_arr_elem > arr[i])
            min_arr_elem = arr[i];
    for (int i = 0; i < array_size; i++)
        if (min_arr_elem == arr[i])
            indx++;
    return indx;
}

int SearchMinElMat(int matrix[4][7], int row, int column) {
    int min_el = matrix[0][0];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (min_el > matrix[i][j])
                min_el = matrix[i][j];
    return min_el;
}

void Print_Matrix_Column(int row, int column, int matrix[row][column]) {
    int minimal_el = SearchMinElMat(matrix, row, column);

    for (int j = 0; j < column; j++)
        for (int i = 0; i < row; i++)
            if (matrix[i][j] == minimal_el) {
                printf("Column %d\n", j);
                break;
            }
}

void CheckArrSize(int arr_size) {
    if (arr_size < 1)
        printf("Invalid Value!");
}

void NewArrSize(int* arr, int* new_arr, int arr_size, int indx) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] >= 0) {
            new_arr = (int*)realloc(new_arr, (indx + 1) * sizeof(int));
            new_arr[indx] = arr[i];
            printf("%4d", new_arr[indx]);
            indx++;
        }
    }
}

void lab1() {
    int digit;
    printf("First_praktik:");

    printf("\nEnter digit: ");
    scanf_s("%d", &digit);

    Check_9(digit);
}

void lab2() {
    const int n = 10;
    int arr_t2[n], k = 0, min_arr_elem;

    printf("\nSecond_praktik:\n");
    Rand_Input_Arr(arr_t2, n);
    Print_Array(arr_t2, n);

    min_arr_elem = arr_t2[0];
    printf("\nThe number of min in the array is equal to %d \n",
        Count_Min_Elem(arr_t2, n, min_arr_elem, k));
}

void lab3() {
    const int row = 4, column = 7;
    int matrix[row][column];

    printf("\nThird praktik:\n");
    Rand_Input_Matrix(row, column, matrix);
    Print_Matrix(row, column, matrix);
    Print_Matrix_Column(row, column, matrix);
}

void lab5() {
    int arr_size, indx = 0;

    printf("\n5th_praktik: \n");

    printf("Enter array size: ");
    scanf_s("%d", &arr_size);

    CheckArrSize(arr_size);

    int* arr = (int*)malloc(sizeof(int) * arr_size);

    Rand_Input_Arr(arr, arr_size);

    printf("\nArray:\n");
    Print_Array(arr, arr_size);

    int* new_arr = NULL;

    printf("\nFinal array:\n");
    NewArrSize(arr, new_arr, arr_size, indx);

    free(arr);
    free(new_arr);;
}

int main() {
    srand(time(NULL));

    lab1();
    lab2();
    lab3();
    lab5();

    return 0;
}