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
    void* (*get)(void*);
    void* (*append)(void*);
    void* (*swap)(void*);
    void* (*free_list)(void*);
    void* (*sort)(void*);
} List;

typedef struct ArgsForDefs{
    List* list;
    Student* student;
    Student* second_student;
    int index;
} ArgsForDefs;

void* list_get(void*);
void* list_append(void*);
void* list_swap(void*);
void* free_list(void*);
void* sort_by_surname(void*);

List* init(List*);

#endif //LABA12_LIST_H
