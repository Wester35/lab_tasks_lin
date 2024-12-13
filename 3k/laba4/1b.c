#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 200

typedef struct {
    char data[MAX_STACK_SIZE];
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

// Проверка, переполнен ли стек
int isFull(Stack *s) {
    return s->top >= MAX_STACK_SIZE - 1;
}

// Добавление элемента в стек
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Ошибка: стек переполнен\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

// Удаление элемента из стека
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Ошибка: стек пуст\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Возвращает приоритет оператора
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

// Проверка, является ли символ оператором
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Конвертация выражения в ОПН
void toRPN(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isdigit(ch)) {
            while (isdigit(infix[i])) { // Обработка многозначных чисел
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Разделяем числа пробелом
            i--;
        } else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(stack.data[stack.top]) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, ch);
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            if (isEmpty(&stack) || stack.data[stack.top] != '(') {
                printf("Ошибка: несоответствие скобок\n");
                exit(1);
            }
            pop(&stack); // Удаляем '('
        } else if (!isspace(ch)) {
            printf("Ошибка: некорректный символ '%c'\n", ch);
            exit(1);
        }
    }

    while (!isEmpty(&stack)) {
        if (stack.data[stack.top] == '(') {
            printf("Ошибка: несоответствие скобок\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0'; // Удаляем последний пробел
}

// Вычисление ОПН
double evaluateRPN(char *expression) {
    double stack[MAX_STACK_SIZE];
    int top = -1;

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) { // Обработка отрицательных чисел
            stack[++top] = atof(token);
        } else if (isOperator(token[0]) && strlen(token) == 1) {
            if (top < 1) {
                printf("Ошибка: некорректное выражение\n");
                exit(1);
            }
            double b = stack[top--];
            double a = stack[top--];
            switch (token[0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Ошибка: деление на ноль\n");
                        exit(1);
                    }
                    stack[++top] = a / b;
                    break;
            }
        } else {
            printf("Ошибка: некорректный токен '%s'\n", token);
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    if (top != 0) {
        printf("Ошибка: некорректное выражение\n");
        exit(1);
    }

    return stack[top];
}

int main() {
    char infix[MAX_EXPR_SIZE], postfix[MAX_EXPR_SIZE];

    printf("Введите числовое выражение: ");
    fgets(infix, MAX_EXPR_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    toRPN(infix, postfix);
    printf("Обратная польская запись: %s\n", postfix);

    double result = evaluateRPN(postfix);
    printf("Результат: %f\n", result);

    return 0;
}
