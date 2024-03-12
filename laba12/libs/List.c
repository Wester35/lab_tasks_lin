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

void sort_by_surname(List* list, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (strcmp(list->get(list, j)->surname,
                       list->get(list, j + 1)->surname) > 0)
                list_swap(list, list->get(list, j), list->get(list, j + 1));
}


void free_list(List* list) {
    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;
        free(current->value);
        free(current);
        current = next;
    }

    free(list);
}

Student* list_get(List* list, int index) {
    int i = 0;

    for (   Node* cur_elem = list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next) {
        if (i == index)
            return cur_elem->value;
        i++;
    }

    printf("Такого элемента в списке нет\n");
    return NULL;
}

void list_append(List* list, Student* student) {
    Node* new_node = malloc(sizeof(Node));
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

bool list_swap(List* list, Student* first_student, Student* second_student) {
    Node* prev_first_elem = NULL;
    Node* prev_second_elem = NULL;

    for (   Node* cur_elem = list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next) {
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

    Student* tmp_student = prev_first_elem->value;
    prev_first_elem->value = prev_second_elem->value;
    prev_second_elem->value = tmp_student;

    return true;
}