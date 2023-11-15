#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int asize = 255, count = 0, check = 0;

    char* arr = (char*) malloc(sizeof(char) * asize);

    fgets(arr, asize, stdin);

    if (strlen(arr) > 4 && arr[3] != '\n') {
        check++;
        char* wrds = strtok(arr, " ,.?!");
        while (wrds) {
            if (strlen(wrds) == 3)
                count++;
            wrds = strtok(NULL, " ,.?!");
        }
    } else {
        count++;
        check++;
    }

    if ((strlen(arr) == 3) && (check == 0))
        count++;

    char* wrds = NULL;


    printf("The number of words with a length of 3: %d\n", count);

    free(arr);

    return 0;
}