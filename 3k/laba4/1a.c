#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

// Инициализация стека
void initStack(Stack *s) {
    s->top = -1;
}

// Проверка, пуст ли стек
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Добавление элемента в стек
void push(Stack *s, double value) {
    if (s->top >= MAX_STACK_SIZE - 1) {
        printf("Ошибка: стек переполнен\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

// Удаление элемента из стека
double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Ошибка: стек пуст\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Вычисление ОПН
double evaluateRPN(char *expression) {
    Stack stack;
    initStack(&stack);

    for (char *token = expression; *token != '\0'; token++) {
        if (isdigit(*token)) {
            // Если цифра, преобразуем в число и кладем в стек
            push(&stack, *token - '0');
        } else if (*token == ' ') {
            continue; // Игнорируем пробелы
        } else {
            // Если оператор, выполняем соответствующую операцию
            double b = pop(&stack);
            double a = pop(&stack);
            switch (*token) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': 
                    if (b == 0) {
                        printf("Ошибка: деление на ноль\n");
                        exit(1);
                    }
                    push(&stack, a / b); 
                    break;
                default:
                    printf("Ошибка: неизвестный оператор '%c'\n", *token);
                    exit(1);
            }
        }
    }

    // Возвращаем результат
    if (stack.top != 0) {
        printf("Ошибка: некорректное выражение\n");
        exit(1);
    }
    return pop(&stack);
}

int main() {
    char input[MAX_STACK_SIZE];

    clock_t start_time, end_time;
    double execution_time;

    start_time = clock();

    printf("Введите выражение в ОПЗ: ");
    fgets(input, MAX_STACK_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("Результат: %f\n", evaluateRPN(input));

    end_time = clock();

    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Время выполнения программы: %f\n", execution_time);
    return 0;
}
