#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "task4.c";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Ошибка открытия файла");
        return EXIT_FAILURE;
    }

    printf("%s\n\n", filename);

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
