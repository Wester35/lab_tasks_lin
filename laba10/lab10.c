#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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

struct Node {
    struct Student* value;
    struct Node* next;
};

struct List {
    struct Node* head;
    struct Node* end;
    unsigned long int size;
    void (*insert)(struct List* list, struct Student* student, int index);
    struct Student* (*erase)(struct List* list, int index);
    struct Student* (*get)(struct List* list, int index);
    void (*append)(struct List* list, struct Student* student);
    bool (*swap)(struct List* list, struct Student* first_student,
                 struct Student* second_student);
    void (*free_list)(struct List* list);
    void (*surname_sort_asc)(struct List* list, int size);
};

void list_insert(struct List* list, struct Student* student, int index);
struct Student* list_erase(struct List* list, int index);
struct Student* list_get(struct List* list, int index);
void list_append(struct List* list, struct Student* student);
bool list_swap(struct List* list, struct Student* first_student,
                struct Student* second_student);
void free_list(struct List* list);
void surname_sort_asc(struct List* list, int size);

struct List* init(struct List* result) {
    result = malloc(sizeof(struct List));
    result->head = NULL;
    result->end = NULL;
    result->size = 0;
    result->insert = list_insert;
    result->erase = list_erase;
    result->get = list_get;
    result->append = list_append;
    result->swap = list_swap;
    result->free_list = free_list;
    result->surname_sort_asc = surname_sort_asc;
    return result;
}

int main() {
    srand(time(NULL));
    system("chcp 65001");

    const int size_stud = 10;
    struct List* students = init(students);

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

        students->append(students, student);
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

void surname_sort_asc(struct List* list, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (strcmp(list->get(list, j)->surname, list->get(list, j + 1)->surname) > 0)
                list_swap(list, list->get(list, j), list->get(list, j + 1));
}

void print_stud(struct Student* student){
    printf("\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
           "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
           student->surname, student->name, student->gender, student->age, student->group,
           student->math_mark, student->phys_mark, student->chemistry_mark);
}

void list_insert(struct List* list, struct Student* student, int index) {
    if (index < -1 || index > list->size) {
        return;
    }

    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->value = student;
    new_node->next = NULL;

    if (list->size == 0) {
        list->end = new_node;
        list->head = new_node;
        list->size += 1;
    } else {
        if (index == 0) {
            new_node->next = list->head;
            list->head = new_node;
            list->size += 1;
        }

        int i = 0;
        for (struct Node* cur_elem = list->head; cur_elem != NULL; cur_elem = cur_elem->next) {
            if (i == index - 1) {
                new_node->next = cur_elem->next;
                cur_elem->next = new_node;
                list->size += 1;
                return;
            }
            i++;
        }
    }
}

void free_list(struct List* list) {
    struct Node* current = list->head;

    while (current != NULL) {
        struct Node* next = current->next;
        free(current->value);
        free(current);
        current = next;
    }

    free(list);
}

struct Student* list_erase(struct List* list, int index) {
    int i = 0;
    struct Node* prev_elem = NULL;

    if (index == 0) {
        struct Student* result = list->head->value;
        struct Node* elem = list->head;
        list->head = list->head->next;
        list->size -= 1;
        free(elem);
        return result;
    }

    for (struct Node* cur_elem = list->head; cur_elem != NULL; cur_elem = cur_elem->next) {
        if (i == index) {
            struct Student* result = cur_elem->value;
            struct Node* elem = cur_elem;

            prev_elem->next = cur_elem->next;
            list->size -= 1;
            free(elem);
            return result;
        }
        prev_elem = cur_elem;
        i++;
    }

    printf("Такого элемента не существует\n");
    return NULL;
}

struct Student* list_get(struct List* list, int index) {
    int i = 0;

    for (struct Node* cur_elem = list->head; cur_elem != NULL; cur_elem = cur_elem->next) {
        if (i == index)
            return cur_elem->value;
        i++;
    }

    printf("Такого элемента в списке нет\n");
    return NULL;
}

void list_append(struct List* list, struct Student* student) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->value = student;
    new_node->next = NULL;

    if (list->size == 0) {
        list->end = new_node;
        list->head = new_node;
    } else {
        list->end->next = new_node;
        list->end = new_node;
    }

    list->size += 1;
}

bool list_swap(struct List* list, struct Student* first_student, struct Student* second_student) {
    struct Node* prev_first_elem = NULL;
    struct Node* prev_second_elem = NULL;

    for (struct Node* cur_elem = list->head; cur_elem != NULL; cur_elem = cur_elem->next) {
        if (cur_elem->value == first_student) {
            prev_first_elem = cur_elem;
        }
        if (cur_elem->value == second_student) {
            prev_second_elem = cur_elem;
        }

        if (prev_first_elem != NULL && prev_second_elem != NULL) {
            break;
        }
    }

    if (prev_first_elem == NULL || prev_second_elem == NULL) {
        printf("Ошибка поиска элементов\n");
        return false;
    }

    struct Student* tmp_student = prev_first_elem->value;
    prev_first_elem->value = prev_second_elem->value;
    prev_second_elem->value = tmp_student;

    return true;
}