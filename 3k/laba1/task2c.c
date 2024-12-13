#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

void handle_error(int error_code) {
    switch (error_code) {
        case 0:
            printf("Криптографическая программа выполнена успешно.\n");
            break;
        case 1:
            fprintf(stderr, "Ошибка: Неверные аргументы при вызове программы.\n");
            break;
        case 2:
            fprintf(stderr, "Ошибка: Файл не найден.\n");
            break;
        case 3:
            fprintf(stderr, "Ошибка: Неизвестный режим работы программы.\n");
            break;
        default:
            fprintf(stderr, "Ошибка: Неизвестный код ошибки (%d).\n", error_code);
            break;
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Введите команду для запуска криптографической программы:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char *args[MAX_INPUT_SIZE / 2 + 1];
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL && i < (MAX_INPUT_SIZE / 2)) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (i == 0) {
        fprintf(stderr, "Ошибка: Не введена команда.\n");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            handle_error(exit_code);
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Программа завершилась с сигналом: %d\n", WTERMSIG(status));
        } else {
            fprintf(stderr, "Программа завершилась неожиданным образом.\n");
        }
    } else {
        perror("fork");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
