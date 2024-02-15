#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>s


const char femaleNames[10][20] = {
        "Natasha",
        "Ilya",
        "Sasha",
        "Valya",
        "Buzya",
        "Maria",
        "Olga",
        "Anna",
        "Tatiana",
        "Yulia"
};

const char maleNames[10][20] = {
        "Masha",
        "Artem",
        "Vasya",
        "Kuzya",
        "Misha",
        "Dmitry",
        "Ivan",
        "Alexey",
        "Sergei",
        "Pavel"
};

const char femaleSurnames[10][20] = {
        "Ivanova",
        "Sidorova",
        "Popova",
        "Vasilieva",
        "Novikova",
        "Petrova",
        "Smirnova",
        "Kuznetsova",
        "Mikhailova",
        "Fedorova"
};

const char maleSurnames[10][20] = {
        "Petrov",
        "Smirnov",
        "Kuznetsov",
        "Mikhailov",
        "Fedorov",
        "Ivanov",
        "Sidorov",
        "Popov",
        "Vasiliev",
        "Novikov"
};

struct Student {
    char surname[20];
    char name[20];
    char gender[6];
    int age;
    int group;
    int math_mark;
    int phys_mark;
    int chemistry_mark;
    void (*printStudent)(struct Student* student);
};

void print_stud(struct Student* student);

struct Tree {
    struct Student *student;
    struct Tree* left;
    struct Tree* right;
    int cnt;
    void (*add_node)(struct Tree* node, struct Student student);
    void (*print)(struct Tree* node);
    void (*clear)(struct Tree* node);
};

void tree_add_node(struct Tree* node, struct Student student);
void tree_print(struct Tree* node);
void tree_clear(struct Tree* node);

struct Tree* tree_init(struct Student student) {
    struct Tree* result = malloc(sizeof(struct Tree));
    result->student = student;
    result->cnt = 1;
    result->add_node = tree_add_node;
    result->right = NULL;
    result->left = NULL;
    result->print = tree_print;
    result->clear = tree_clear;

    return result;
}

int main() {
    srand(time(NULL));
    system("chcp 65001");

    const int size_stud = 10;
    struct Student* stud;
    struct Tree* students = tree_init(*stud);

    printf("******Before******");

    for (int i = 0; i < size_stud; i++) {
        struct Student* student = malloc(sizeof(struct Student));
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

        students->add_node(students, *student);
        student->printStudent(list_get(students, i));
    }

    printf("\n\n******After******");
    students->surname_sort_asc(students, size_stud);
    for (int i = 0; i < size_stud; i++){
        print_stud(list_get(students, i));
    }
    students->free_list(students);
    return 0;
}

void tree_add_node(struct Tree* node, struct Student student) {
    int cmp = strcmp(node->student.surname, student.surname);

    if (cmp < 0) {
        if (node->left == NULL) {
            node->left = tree_init(student);
            return;
        }
        tree_add_node(node->left, student);
        return;
    } else if (cmp > 0) {
        if (node->right == NULL) {
            node->right = tree_init(student);
            return;
        }
        tree_add_node(node->right, student);
        return;
    } else {
        node->cnt++;
        return;
    }
}

void tree_print(struct Tree* node) {
    struct Student* student;
    if (node == NULL) {
        return;
    }
    tree_print(node->right);
    print_stud(&*node->student);
    tree_print(node->left);
}

void tree_clear(struct Tree* node) {
    if (node->left != NULL)
        tree_clear(node->left);
    if (node->right != NULL)
        tree_clear(node->right);
    free(node);
}

void print_stud(struct Student* student){
    printf("\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
           "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
           student->surname, student->name, student->gender, student->age, student->group,
           student->math_mark, student->phys_mark, student->chemistry_mark);
}


