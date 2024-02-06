#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


struct Student {
    char* surname;
    char* name;
    char* gender;
    int age;
    char* group;
    int math_mark;
    int phys_mark;
    int chemistry_mark;
};

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
    bool (*swap)(struct List* list, int first_index, int second_index);
};

void list_insert(struct List* list, struct Student* student, int index);
struct Student* list_erase(struct List* list, int index);
struct Student* list_get(struct List* list, int index);
void list_append(struct List* list, struct Student* student);
bool list_swap(struct List* list, int first_index, int second_index);

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
    return result;
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

bool list_swap(struct List* list, int first_index, int second_index) {
    if (first_index < 0 || first_index >= list->size || second_index < 0 || second_index >= list->size) {
        printf("Указаны неверные индексы");
        return false;
    }

    int i = 0;
    struct Node* prev_first_elem = NULL;

    for (struct Node* cur_elem = list->head; cur_elem != NULL; cur_elem = cur_elem->next) {
        if (i == first_index) {
            break;
        }
        prev_first_elem = cur_elem;
        i++;
    }

    i = 0;
    struct Node* prev_second_elem = NULL;

    for (struct Node* cur_elem = list->head; cur_elem != NULL; cur_elem = cur_elem->next) {
        if (i == second_index) {
            break;
        }
        prev_second_elem = cur_elem;
        i++;
    }

    struct Node* tmp = prev_first_elem->next;
    prev_first_elem->next = prev_second_elem->next;
    prev_second_elem->next = tmp;

    tmp = prev_first_elem->next->next;
    prev_first_elem->next->next = prev_second_elem->next->next;
    prev_second_elem->next->next = tmp;

    return true;
}

void print_stud(struct Student* student);


int main(){
    system("chcp 65001");
    struct List* students = init(students);
    struct Student student1 =
            {"Карташов", "Антон", "М",
             17, "ИСП-206", 5, 3, 4};
    students->append(students, &student1);
    print_stud(list_get(students, 0));
    return 0;
}

void print_stud(struct Student* student){
    printf("Surname: %s\nName: %s\nGender: %s\nAge: %d\n"
           "Group: %s\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
           student->surname, student->name, student->gender, student->age, student->group,
           student->math_mark, student->phys_mark, student->chemistry_mark);
}
