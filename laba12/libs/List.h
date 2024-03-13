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
    Student* value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* end;
    unsigned long int size;
    void* (*get)(void* args);
    void* (*append)(void* args);
    void* (*swap)(void* args);
    void* (*free_list)(void* args);
    void (*sort)(void* args);
} List;

typedef struct ArgsForDefs{
    List* list;
    Student* student1;
    Student* student2;
    int index;
} ArgsForDefs;

void* list_get(void* args);
void* list_append(void* args);
void* list_swap(void* args);
void* free_list(void* args);
void* sort_by_surname(void* args);

List* init(List* result);

#endif //LABA12_LIST_H
