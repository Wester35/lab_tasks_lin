#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int row = 4, column = 7;
    int matrix[row][column], min;

    srand(time(NULL));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = rand() % 6 - 1;

    min = matrix[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%4d ", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (min > matrix[i][j])
                min = matrix[i][j];

    for (int j = 0; j < column; j++)
    {
        check = false;
        for (int i = 0; i < row; i++)
            if (matrix[i][j] == min) {
                printf("Column %d\n", j);
                break;
            }
    }

    return 0;
}
