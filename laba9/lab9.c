#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


bool Check_9(int);

void Rand_Input_Arr(int*, int);

void Rand_Input_Matrix(int**, int, int);

void Print_Array(int*, int);

void Print_Matrix(int**, int, int);

int SearchMinEl(int*, int);

int Count_Min_Elem(int*, int, int, int);

int SearchMinElMat(int**, int, int);

void Print_Index_Matrix_Column(int**, int, int);

bool CheckArrSize(int);

int* CreateNewArray(int*, int, int*);

int** make_dynamic_matrix(int, int);

void free_matrix_memory(int**, int);

void lab1();

void lab2();

void lab3();

void lab5();

int main()
{
    srand(time(NULL));

    void (*lab_p) (void);
    lab_p = lab1;
    lab_p();
    lab_p = lab2;
    lab_p();
    lab_p = lab3;
    lab_p();
    lab_p = lab5;
    lab_p();
    printf("\n\n*********************************\n\n");
    return 0;
}


bool Check_9(int digit)
{
    if (digit % 9 == 0)
        return true;
    else
        return false;
}


void Rand_Input_Arr(int* arr, int array_size)
{
    for (int i = 0; i < array_size; i++)
        arr[i] = rand() % 21 - 10;
}


void Rand_Input_Matrix(int** arr, int size_m, int size_n)
{
    for (int i = 0; i < size_m; i++)
        for (int j = 0; j < size_n; j++)
            arr[i][j] = rand() % 7 - 1;
}


void Print_Array(int* arr, int array_size)
{
    for (int i = 0; i < array_size; i++)
        printf("%4d", arr[i]);
}


void Print_Matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}


int SearchMinEl(int* arr, int array_size)
{
    int min_arr_elem = arr[0];
    for (int i = 1; i < array_size; i++)
        if (min_arr_elem > arr[i])
            min_arr_elem = arr[i];
    return min_arr_elem;
}


int Count_Min_Elem(int* arr, int array_size, int min_arr_elem, int indx)
{
    for (int i = 0; i < array_size; i++)
        if (min_arr_elem == arr[i])
            indx++;
    return indx;
}


int SearchMinElMat(int** matrix, int row, int column)
{
    int min_el = matrix[0][0];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (min_el > matrix[i][j])
                min_el = matrix[i][j];
    return min_el;
}


void Print_Index_Matrix_Column(int** matrix, int row, int column)
{
    int (*minimal_el)(int**, int, int);
    minimal_el = SearchMinElMat;
    for (int j = 0; j < column; j++)
        for (int i = 0; i < row; i++)
            if (matrix[i][j] == minimal_el(matrix, row, column)) {
                printf("Column %d\n", j);
                break;
            }
}


bool CheckArrSize(int arr_size)
{
    if (arr_size < 1)
        return false;
    else
        return true;
}


int* CreateNewArray(int* arr, int arr_size, int* new_size)
{
    int* new_arr = NULL;
    int indx = 0;

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] >= 0)
        {
            new_arr = (int*)realloc(new_arr, (indx + 1) * sizeof(int));
            new_arr[indx] = arr[i];
            indx++;
        }
    }

    *new_size = indx;
    return new_arr;
}


void lab1()
{
    bool (*check)(int);
    check = Check_9;
    int digit;
    printf("First_praktik:");

    printf("\nEnter digit: ");
    scanf("%d", &digit);

    if (check(digit))
        printf("Yes");
    else
        printf("No");
}


void lab2()
{
    const int n = 10;
    int arr_t2[n], k = 0;
    void (*arr_interaction_p)(int*, int);
    int (*search_element_p)(int*, int);
    int (*count_element_p)(int*, int, int, int);
    printf("\nSecond_praktik:\n");
    arr_interaction_p = Rand_Input_Arr;
    arr_interaction_p(arr_t2, n);
    arr_interaction_p = Print_Array;
    arr_interaction_p(arr_t2, n);
    search_element_p = SearchMinEl;
    count_element_p = Count_Min_Elem;
    printf("\nThe number of min in the array is equal to %d \n",
           count_element_p(arr_t2, n, search_element_p(arr_t2, n), k));
}


void lab3()
{
    const int row = 4, column = 7;
    int** (*make_matrix_p)(int, int);
    void (*free_matrix_p)(int**, int);
    void* (*matrix_interaction_p)(int**, int, int); /////
    make_matrix_p = &make_dynamic_matrix;
    free_matrix_p = free_matrix_memory;
    int **matrix = make_matrix_p(row, column);
    printf("\nThird praktik:\n");
    Rand_Input_Matrix(matrix, row, column);
    Print_Matrix(matrix, row, column);
    Print_Index_Matrix_Column(matrix, row, column);
    free_matrix_p(matrix, row);
}


int** make_dynamic_matrix(int rows, int cols)
{
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}


void free_matrix_memory(int** matrix, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        free(matrix[i]);
        matrix[i] = NULL;
    }
    free(matrix);
}


void lab5()
{
    int arr_size, indx = 0;

    printf("\n5th_praktik: \n");

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    if (CheckArrSize(arr_size))
    {
        int* arr = (int*)malloc(sizeof(int) * arr_size);

        Rand_Input_Arr(arr, arr_size);

        printf("\nArray:\n");
        Print_Array(arr, arr_size);

        int* new_arr = CreateNewArray(arr, arr_size, &indx);

        printf("\nFinal array:\n");
        Print_Array(new_arr, indx);

        free(arr);
        free(new_arr);
    }
    else
        printf("Invalid value!");
}

//float calculator(str int(*order)(int, int))