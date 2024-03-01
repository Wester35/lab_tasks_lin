//
// Created by wstr on 01.03.2024.
//

#ifndef LABA11MF_TREE_H
#define LABA11MF_TREE_H
#include "Student.h"
#include <stdlib.h>
#include <string.h>
#define Tree() init()

typedef struct TreeNode {
    Student *value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
    void (*add_node)(struct Tree *tree, Student *student);
    void (*clear)(struct Tree *tree);
    void (*print)(struct Tree *tree);
} Tree;

void tree_add_node(Tree *tree, Student *student);
void tree_clear(Tree *tree);
void tree_print(Tree *tree);
void tree_clear_recursive(TreeNode *root);
void tree_print_recursive(TreeNode *root);

Tree *init();

#endif //LABA11MF_TREE_H
