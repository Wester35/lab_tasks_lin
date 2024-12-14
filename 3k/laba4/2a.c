#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VARS 100
#define MAX_VAR_NAME 50
#define MAX_EXPR_LENGTH 100

typedef struct {
    char name[MAX_VAR_NAME];
    int value;
    int initialized;
} Variable;

Variable variables[MAX_VARS];
int var_count = 0;

// Функция для поиска переменной по имени
Variable* find_variable(const char* name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return &variables[i];
        }
    }
    return NULL;
}

// Функция для вычисления значения выражения (простой парсер)
int evaluate_expression(const char* expr) {
    int result = 0;
    char op = '+';
    char token[MAX_EXPR_LENGTH];
    int i = 0, j = 0;

    while (1) {
        if (sscanf(expr + i, "%s%n", token, &j) == 1) {
            i += j;
            Variable* var = find_variable(token);
            int value = (var != NULL && var->initialized) ? var->value : atoi(token);
            
            if (op == '+') {
                result += value;
            } else if (op == '-') {
                result -= value;
            } else if (op == '*') {
                result *= value;
            } else if (op == '/') {
                result /= value;
            }

            // Проверка на наличие следующего оператора
            if (sscanf(expr + i, " %c", &op) == 1) {
                i += 2; // Пропускаем оператор и пробел
            } else {
                break;
            }
        } else {
            break;
        }
    }
    return result;
}

int main() {
    char line[256];
    char var_type[MAX_VAR_NAME];
    char var_name[MAX_VAR_NAME];
    char expr[MAX_EXPR_LENGTH];

    // Чтение строк кода
    while (fgets(line, sizeof(line), stdin)) {
        // Поиск присваивания
        if (sscanf(line, "%s %s = %[^\n];", var_type, var_name, expr) == 3) {
            Variable* var = find_variable(var_name);
            if (var == NULL) {
                strcpy(variables[var_count].name, var_name);
                var = &variables[var_count++];
            }
            var->value = evaluate_expression(expr);
            var->initialized = 1;
        } else if (sscanf(line, "%s %s;", var_type, var_name) == 2) {
            // Объявление переменной без присваивания
            if (find_variable(var_name) == NULL) {
                strcpy(variables[var_count].name, var_name);
                variables[var_count++].initialized = 0;
            }
        }
    }

    // Вывод таблицы переменных
    printf("Таблица переменных:\n");
    for (int i = 0; i < var_count; i++) {
        printf("%s: %d\n", variables[i].name, variables[i].initialized ? variables[i].value : 0);
    }

    // Вывод неинициализированных переменных
    printf("\nНеинициализированные переменные:\n");
    for (int i = 0; i < var_count; i++) {
        if (!variables[i].initialized) {
            printf("%s\n", variables[i].name);
        }
    }

    return 0;
}