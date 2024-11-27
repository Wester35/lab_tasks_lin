//
// Created by wstr on 01.03.2024.
//

#include "Tree.h"

Tree *init() {
    struct Tree *result = malloc(sizeof(struct Tree));
    result->root = NULL;
    result->add_node = tree_add_node;
    result->clear = tree_clear;
    result->print = tree_print;
    return result;
}

void tree_add_node(Tree *tree, Student *student) {
    if (tree->root == NULL) {
        tree->root = malloc(sizeof(TreeNode));
        tree->root->value = student;
        tree->root->left = NULL;
        tree->root->right = NULL;
    } else {
        TreeNode *current = tree->root;
        while (1) {
            if (strcmp(student->surname, current->value->surname) < 0) {
                if (current->left == NULL) {
                    current->left = malloc(sizeof(TreeNode));
                    current->left->value = student;
                    current->left->left = NULL;
                    current->left->right = NULL;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = malloc(sizeof(TreeNode));
                    current->right->value = student;
                    current->right->left = NULL;
                    current->right->right = NULL;
                    break;
                }
                current = current->right;
            }
        }
    }
}

void tree_clear_recursive(TreeNode *root) {
    if (root != NULL) {
        tree_clear_recursive(root->left);
        tree_clear_recursive(root->right);
        free(root->value);
        free(root);
    }
}

void tree_clear(Tree *tree) {
    tree_clear_recursive(tree->root);
    tree->root = NULL;
}

void tree_print_recursive(TreeNode *root) {
    if (root != NULL) {
        tree_print_recursive(root->left);
        root->value->printStudent(root->value);
        //print_stud(root->value);
        tree_print_recursive(root->right);
    }
}

void tree_print(Tree *tree) {
    tree_print_recursive(tree->root);
}