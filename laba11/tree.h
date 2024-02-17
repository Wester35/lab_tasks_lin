//tree.h
// Created by wstr on 17.02.2024.
//

#ifndef LABA11_TREE_H
#define LABA11_TREE_H
#include "student.h"
#include <malloc.h>
#include <stdio.h>

struct Tree {
    struct Student *student;
    struct Tree* left;
    struct Tree* right;
    int cnt;
    void (*add_node)(struct Tree* node, struct Student* student);
    void (*print)(struct Tree* node);
    void (*clear)(struct Tree* node);
};

void tree_add_node(struct Tree* node, struct Student* student);
void tree_print(struct Tree* node);
void tree_clear(struct Tree* node);

struct Tree *tree_init(struct Student* student);
#endif //LABA11_TREE_H

