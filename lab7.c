#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int asize;

    printf("Enter size: ");
    scanf("%d", &asize);

    char* arr = (char*) malloc(sizeof(int) * asize);

    fgets(arr, asize, stdin);

    printf("%s", arr);
}