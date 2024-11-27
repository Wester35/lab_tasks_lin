#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int size = 255;
    unsigned short int check = 0;
    char *input_data = malloc(size * sizeof(char));

    printf("Введите строку: ");
    fgets(input_data, size, stdin);

    input_data[strcspn(input_data, "\n")] = 0;

    if (strlen(input_data) == 0) {
        printf("Строка пустая\n");
        free(input_data);
        return 0;
    }

    for (int i = 0; input_data[i] != '\0'; i++) {
        if (!isdigit(input_data[i])) {
            check = 1;
            break;
        }
    }

    if (check == 1) {
        printf("Строка не является числом\n");
    } else {
        printf("Строка является числом\n");
    }

    free(input_data);
    return 0;
}