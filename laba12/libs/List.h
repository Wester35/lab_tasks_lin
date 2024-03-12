// List.h
// Created by Wstr35 on 12.03.2024.
//

#ifndef LABA12_LIST_H
#define LABA12_LIST_H
#include <stdio.h>
#include <stdbool.h>
#include "Student.h"
#include <stdlib.h>
#include <string.h>
#define List(students) init(students)

typedef struct Node {
    void* value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* end;
    unsigned long int size;
    void* (*get)(struct List* list, int index);
    void (*append)(struct List* list, Student* student);
    void* (*swap)(struct List* list, Student* first_student,
                 Student* second_student);
    void (*free_list)(struct List* list);
    void (*sort)(struct List* list, int size);
} List;

void* list_get(List* list, int index);
void list_append(List* list, Student* student);
void* list_swap(List* list, Student* first_student,
               Student* second_student);
void free_list(List* list);
void sort_by_surname(List* list, int size);

List* init(List* result);

#endif //LABA12_LIST_H
