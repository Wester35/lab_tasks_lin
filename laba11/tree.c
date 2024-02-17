//tree.c
// Created by wstr on 17.02.2024.
//

#include "tree.h"
#include "student.h"
#include <malloc.h>
#include <string.h>

struct Tree* tree_init(struct Student* student) {
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

void tree_add_node(struct Tree* node, struct Student* student) {
    int cmp = strcmp(node->student->surname, student->surname);

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
//    printf("\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
//           "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
//           node->student->surname, node->student->name, node->student->gender,
//           node->student->age, node->student->group, node->student->math_mark,
//           node->student->phys_mark, node->student->chemistry_mark);
    node->student->printStudent(node->student);
    tree_print(node->left);
}

void tree_clear(struct Tree* node) {
    if (node->left != NULL)
        tree_clear(node->left);
    if (node->right != NULL)
        tree_clear(node->right);
    free(node->student);
    free(node);
}

