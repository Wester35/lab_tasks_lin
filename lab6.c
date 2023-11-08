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

void Print_Array(int* arr, int array_size) {
    for (int i = 0; i < array_size; i++)
        printf("%4d", arr[i]);
}

void Print_Matrix(int matrix[4][7], int row, int column) {
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

void NewArrInput(int* arr, int* new_arr, int arr_size, int new_arr_size, int indx) {
    for (int i = 0; i < arr_size; i++)
        if (arr[i] >= 0 && indx < new_arr_size) {
            new_arr[indx] = arr[i];
            indx++;
        }
        else
            continue;
}

int SearchMinElMat(int matrix[4][7], int row, int column) {
    int min_el = matrix[0][0];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (min_el > matrix[i][j])
                min_el = matrix[i][j];
    return min_el;
}

void Print_Matrix_Column(int matrix[4][7], int row, int column) {
    int minimal_el = SearchMinElMat(matrix, row, column);
    for (int j = 0; j < column; j++)
        for (int i = 0; i < row; i++)
            if (matrix[i][j] == minimal_el) {
                printf("Column %d\n", j);
                break;
            }
}

int NewArrSize(int* arr, int arr_size) {
    int new_arr_size = 0;
    for (int i = 0; i < arr_size; i++)
        if (arr[i] >= 0)
            new_arr_size++;
    return new_arr_size;
}

void CheckArrSize(int arr_size) {
    if (arr_size < 1)
        printf("Invalid Value!");
}

void CheckNewArrSize(int new_arr_size, int* arr) {
    if (new_arr_size < 2) {
        printf("There is no sequence with less than two numbers\n");
        free(arr);
    }
}

void lab1() {
    int digit;
    printf("First_praktik: \n");

    printf("\nEnter digit: ");
    scanf()"%d", &digit);

    Check_9(digit);
}

void lab2() {
    const int n = 10;
    int arr_t2[n], k = 0, min_arr_elem;

    printf("\nSecond_praktik: \n\n");

    Rand_Input_Arr(arr_t2, n);

    Print_Array(arr_t2, n);

    min_arr_elem = arr_t2[0];
    printf("\nThe number of min in the array is equal to %d \n",
        Count_Min_Elem(arr_t2, n, min_arr_elem, k));
}

void lab3() {
    const int row = 4, column = 7;
    int matrix[row][column], min_el;

    printf("\nThird praktik:\n");

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = rand() % 6 - 1;

    min_el = matrix[0][0];

    Print_Matrix(matrix, row, column);
    Print_Matrix_Column(matrix, row, column);
}

void lab5() {
    int arr_size, new_arr_size = 0, indx = 0;

    printf("\n5th_praktik: \n");

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    CheckArrSize(arr_size);

    int* arr = (int*)malloc(sizeof(int) * arr_size);

    Rand_Input_Arr(arr, arr_size);

    new_arr_size = NewArrSize(arr, arr_size);

    CheckNewArrSize(new_arr_size, arr);

    int* new_arr = (int*)calloc(new_arr_size, sizeof(int));

    NewArrInput(arr, new_arr, arr_size, new_arr_size, indx);

    Print_Array(arr, arr_size);
    free(arr);

    printf("\nFinal array:\n");

    Print_Array(new_arr, new_arr_size);
    free(new_arr);
}

int main() {
    srand(time(NULL));

    //первая практика
    lab1();

    //вторая практика
    lab2();

    //третья практика
    lab3();

    //пятая практика
    lab5();

    return 0;
}