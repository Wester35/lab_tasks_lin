// List.c
// Created by Wstr35 on 12.03.2024.
//

#include "List.h"


List* init(List* result) {
    result = malloc(sizeof(List));
    result->head = NULL;
    result->end = NULL;
    result->size = 0;
    result->get = list_get;
    result->append = list_append;
    result->swap = list_swap;
    result->free_list = free_list;
    result->sort = sort_by_surname;
    return result;
}

void* sort_by_surname(void* args) {
    ArgsForDefs* _args = args;
    List* list = _args->list;
    ArgsForDefs* list_get1 = _args;
    ArgsForDefs* list_get2 = _args;
    for (int i = 0; i < list->size - 1; i++){
        for (int j = 0; j < list->size - i - 1; j++){
            list_get1->index = j;
            list_get2->index = j + 1;
            _args->student1 = list->get(list_get1);
            _args->student2 = list->get(list_get2);
            if (strcmp(_args->student1->surname,
                       _args->student2->surname) > 0){
                list_swap(_args);
            }
        }
    }
    return NULL;
}

void* free_list(void* args) {
    if (args == NULL) {
        return NULL;
    }

    ArgsForDefs* _args = (ArgsForDefs*)args;
    Node* current = _args->list->head;

    while (current != NULL) {
        Node* next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(_args->list);
    return NULL;
}

void* list_get(void* args) {
    int i = 0;
    ArgsForDefs* _args = args;
    for (   Node* cur_elem = _args->list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next) {
        if (i == _args->index)
            return cur_elem->value;
        i++;
    }

    printf("Такого элемента в списке нет\n");
    return NULL;
}

void* list_append(void* args) {
    ArgsForDefs* _args = args;
    Node* new_node = malloc(sizeof(Node));
    new_node->value = _args->student1;
    new_node->next = NULL;

    if (_args->list->size == 0) {
        _args->list->end = new_node;
        _args->list->head = new_node;
    } else {
        _args->list->end->next = new_node;
        _args->list->end = new_node;
    }

    _args->list->size += 1;
    return NULL;
}

void* list_swap(void* args) {
    bool* result;
    Node* prev_first_elem = NULL;
    Node* prev_second_elem = NULL;
    ArgsForDefs* _args = args;
    for (   Node* cur_elem = _args->list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next) {
        if (cur_elem->value == _args->student1) {
            prev_first_elem = cur_elem;
        }
        if (cur_elem->value == _args->student2) {
            prev_second_elem = cur_elem;
        }

        if (prev_first_elem != NULL && prev_second_elem != NULL) {
            break;
        }
    }

    if (prev_first_elem == NULL || prev_second_elem == NULL) {
        printf("Ошибка поиска элементов\n");
        *result = false;
        return result;
    }

    Student* tmp_student = prev_first_elem->value;
    prev_first_elem->value = prev_second_elem->value;
    prev_second_elem->value = tmp_student;
    *result = true;
    return result;
}