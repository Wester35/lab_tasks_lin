#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

const char femaleNames[10][20] = {"Natasha", "Ilya", "Sasha", "Valya", "Buzya", "Maria", "Olga", "Anna", "Tatiana", "Yulia"};

const char maleNames[10][20] = {"Masha", "Artem", "Vasya", "Kuzya", "Misha", "Dmitry", "Ivan", "Alexey", "Sergei", "Pavel"};

const char femaleSurnames[10][20] = {"Ivanova", "Sidorova", "Popova", "Vasilieva", "Novikova", "Petrova", "Smirnova", "Kuznetsova", "Mikhailova", "Fedorova"};

const char maleSurnames[10][20] = {"Petrov", "Smirnov", "Kuznetsov", "Mikhailov", "Fedorov", "Ivanov", "Sidorov", "Popov", "Vasiliev", "Novikov"};

struct Student {
    char surname[20];
    char name[20];
    char gender[6];
    int age;
    int group;
    int math_mark;
    int phys_mark;
    int chemistry_mark;
    void (*printStudent)(struct Student *student);
};

void print_stud(struct Student *student);

struct TreeNode {
    struct Student *value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Tree {
    struct TreeNode *root;
    void (*add_node)(struct Tree *tree, struct Student *student);
    void (*clear)(struct Tree *tree);
    void (*print)(struct Tree *tree);
};

void tree_add_node(struct Tree *tree, struct Student *student);
void tree_clear(struct Tree *tree);
void tree_print(struct Tree *tree);

struct Tree *init() {
    struct Tree *result = malloc(sizeof(struct Tree));
    result->root = NULL;
    result->add_node = tree_add_node;
    result->clear = tree_clear;
    result->print = tree_print;
    return result;
}

int main() {
    srand(time(NULL));

    const int size_stud = 10;
    struct Tree *students = init();

    printf("******Before******");

    for (int i = 0; i < size_stud; i++) {
        struct Student *student = malloc(sizeof(struct Student));
        student->printStudent = print_stud;

        if (rand() % 2 == 1) {
            strcpy(student->surname, maleSurnames[rand() % 10]);
            strcpy(student->name, maleNames[rand() % 10]);
            strcpy(student->gender, "Male");
        } else {
            strcpy(student->surname, femaleSurnames[rand() % 10]);
            strcpy(student->name, femaleNames[rand() % 10]);
            strcpy(student->gender, "Female");
        }

        student->age = rand() % 5 + 16;
        student->group = rand() % 5 + 1;
        student->math_mark = rand() % 3 + 3;
        student->phys_mark = rand() % 3 + 3;
        student->chemistry_mark = rand() % 3 + 3;

        students->add_node(students, student);
        student->printStudent(student);
    }

    printf("\n\n******After******");
    students->print(students);
    students->clear(students);
    free(students);

    return 0;
}

void tree_add_node(struct Tree *tree, struct Student *student) {
    if (tree->root == NULL) {
        tree->root = malloc(sizeof(struct TreeNode));
        tree->root->value = student;
        tree->root->left = NULL;
        tree->root->right = NULL;
    } else {
        struct TreeNode *current = tree->root;
        while (1) {
            if (strcmp(student->surname, current->value->surname) < 0) {
                if (current->left == NULL) {
                    current->left = malloc(sizeof(struct TreeNode));
                    current->left->value = student;
                    current->left->left = NULL;
                    current->left->right = NULL;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = malloc(sizeof(struct TreeNode));
                    current->right->value = student;
                    current->right->left = NULL;
                    current->right->right = NULL;
                    break;
                }
                current = current->right;
            }
        }
    }
}

void tree_clear_recursive(struct TreeNode *root) {
    if (root != NULL) {
        tree_clear_recursive(root->left);
        tree_clear_recursive(root->right);
        free(root->value);
        free(root);
    }
}

void tree_clear(struct Tree *tree) {
    tree_clear_recursive(tree->root);
    tree->root = NULL;
}

void tree_print_recursive(struct TreeNode *root) {
    if (root != NULL) {
        tree_print_recursive(root->left);
        print_stud(root->value);
        tree_print_recursive(root->right);
    }
}

void tree_print(struct Tree *tree) {
    tree_print_recursive(tree->root);
}

void print_stud(struct Student *student) {
    printf("\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
           "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
           student->surname, student->name, student->gender, student->age, student->group,
           student->math_mark, student->phys_mark, student->chemistry_mark);
}
