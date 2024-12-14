#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_VARS 100
#define MAX_EXPR_SIZE 200
#define MAX_STACK_SIZE 100

typedef struct {
    char name[50];
    int assigned;  // 1, если присвоено значение, 0 - если нет
    double value;
} Variable;

Variable vars[MAX_VARS];
int var_count = 0;

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, double value) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++(stack->top)] = value;
    }
}

double pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
    return 0.0;
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void toRPN(const char *expr, char *output) {
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isdigit(ch) || (ch == '.' || (ch == '-' && isdigit(expr[i + 1])))) {
            // Если цифра, добавляем в результат
            while (isdigit(expr[i]) || expr[i] == '.' || expr[i] == '-') {
                output[j++] = expr[i++];
            }
            output[j++] = ' ';
            i--;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                output[j++] = pop(&stack);
                output[j++] = ' ';
            }
            pop(&stack);  // удаляем '('
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!isEmpty(&stack) && precedence(stack.data[stack.top]) >= precedence(ch)) {
                output[j++] = pop(&stack);
                output[j++] = ' ';
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        output[j++] = pop(&stack);
        output[j++] = ' ';
    }
    output[j] = '\0';
}

double evaluateRPN(const char *expr) {
    Stack stack;
    initStack(&stack);
    double result = 0;
    char temp[MAX_EXPR_SIZE];
    int j = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isdigit(ch) || ch == '.' || (ch == '-' && isdigit(expr[i + 1]))) {
            // Чтение числа
            while (isdigit(expr[i]) || expr[i] == '.' || expr[i] == '-') {
                temp[j++] = expr[i++];
            }
            temp[j] = '\0';
            push(&stack, atof(temp));
            j = 0;
            i--;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            double val2 = pop(&stack);
            double val1 = pop(&stack);

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

// Функция для добавления переменной в таблицу
void addVariable(const char *name, int assigned, double value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            // Если переменная уже существует, обновляем её значение
            vars[i].assigned = assigned;
            vars[i].value = value;
            return;
        }
    }
    // Если переменная не существует, добавляем новую
    strcpy(vars[var_count].name, name);
    vars[var_count].assigned = assigned;
    vars[var_count].value = value;
    var_count++;
}

// Функция для вывода таблицы переменных
void printVariables() {
    printf("Таблица переменных:\n");
    printf("Имя переменной\tПрисвоено значение\tЗначение\n");
    for (int i = 0; i < var_count; i++) {
        if (vars[i].assigned) {  // Только переменные с присвоенным значением
            printf("%s\t\t%s\t\t%lf\n", vars[i].name, vars[i].assigned ? "Да" : "Нет", vars[i].value);
        }
    }
}

// Функция для вывода переменных без присвоенного значения
void printUnassignedVariables() {
    printf("Переменные без присвоенного значения:\n");
    for (int i = 0; i < var_count; i++) {
        if (!vars[i].assigned) {
            printf("%s\n", vars[i].name);
        }
    }
}

// Функция для вычисления значения переменных
void evaluateVariables() {
    for (int i = 0; i < var_count; i++) {
        if (vars[i].assigned) {
            // Если переменная имеет значение
            printf("Переменная %s имеет значение %lf\n", vars[i].name, vars[i].value);
        } else {
            printf("Переменная %s не имеет присвоенного значения\n", vars[i].name);
        }
    }
}

// Функция для вычисления значения переменной из выражения с учётом других переменных
double evaluateVariableExpression(const char *expression) {
    char rpn[MAX_EXPR_SIZE];
    char expr_with_vars[MAX_EXPR_SIZE];
    int j = 0, k = 0;

    // Заменяем переменные на их значения в строке выражения
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isalpha(expression[i])) {
            char var_name[50];
            int var_len = 0;

            // Чтение имени переменной
            while (isalpha(expression[i]) || expression[i] == '_') {
                var_name[var_len++] = expression[i++];
            }
            var_name[var_len] = '\0';

            // Найдем значение переменной
            int var_found = 0;
            for (int v = 0; v < var_count; v++) {
                if (strcmp(vars[v].name, var_name) == 0 && vars[v].assigned) {
                    sprintf(&expr_with_vars[k], "%lf", vars[v].value);
                    k += strlen(&expr_with_vars[k]);
                    var_found = 1;
                    break;
                }
            }

            if (!var_found) {
                // Если переменной нет в таблице, оставляем её как есть
                sprintf(&expr_with_vars[k], "%s", var_name);
                k += strlen(&expr_with_vars[k]);
            }
            i--;
        } else {
            expr_with_vars[k++] = expression[i];
        }
    }
    expr_with_vars[k] = '\0';

    // Преобразуем выражение с переменными в обратную польскую запись
    toRPN(expr_with_vars, rpn);
    return evaluateRPN(rpn);
}

// Проверка, является ли символ буквой или цифрой
int isIdentifierChar(char c) {
    return isalnum(c) || c == '_';
}

// Функция для парсинга строки программы и извлечения переменных и их значений
void parseProgram(const char *code) {
    char var_name[50];
    int i = 0, j = 0;
    double temp_value;
    char temp_expr[MAX_EXPR_SIZE];
    int in_expr = 0;

    while (code[i] != '\0') {
        if (isalpha(code[i]) || code[i] == '_') {
            // Начало имени переменной
            j = 0;
            while (isIdentifierChar(code[i])) {
                var_name[j++] = code[i++];
            }
            var_name[j] = '\0';

            // Игнорируем типы данных, такие как "int", "float", и т.д.
            if (strcmp(var_name, "int") == 0 || strcmp(var_name, "float") == 0) {
                continue;
            }

            // Следующая позиция должна быть '=' для присваивания
            if (code[i] == '=') {
                i++;

                // Чтение выражения для присваивания
                j = 0;
                while (code[i] != ';' && code[i] != '\0') {
                    temp_expr[j++] = code[i++];
                }
                temp_expr[j] = '\0';

                // Оценка выражения и присваивание значения переменной
                temp_value = evaluateVariableExpression(temp_expr);
                addVariable(var_name, 1, temp_value);
            }
        }
        i++;
    }
}

int main() {
    const char *program_code = "a=12 b=a+2 c=a*b d=c*2;";
    parseProgram(program_code);

    printVariables();
    printUnassignedVariables();
    evaluateVariables();

    return 0;
}
