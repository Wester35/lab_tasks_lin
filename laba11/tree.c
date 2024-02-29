//tree.c
// Created by wstr on 17.02.2024.
//

#include "tree.h"
#include <malloc.h>
#include <string.h>

Tree* tree_init(Student* stud) {
    struct Tree* result = malloc(sizeof(struct Tree));
    result->cnt = 1;
    result->student = malloc(result->cnt * sizeof(Student));
    result->student[result->cnt - 1] = stud;
    result->add_node = tree_add_node;
    result->right = NULL;
    result->left = NULL;
    result->print = tree_print;
    result->clear = tree_clear;

    return result;
}

//void tree_add_node(Tree* node, Student* student) {
//    //int //cmp = strcmp(node->student[node->cnt - 1]->surname, student->surname);
//
//    if (strcmp(node->student[node->cnt - 1]->surname, student->surname) < 0) {
//        if (node->left == NULL) {
//            node->left = tree_init(student);  // Используйте tree_init
//            return;
//        }
//        node->add_node(node->left, student);
//        return;
//    }
//
//    if (strcmp(node->student[node->cnt - 1]->surname, student->surname) > 0) {
//        if (node->right == NULL) {
//            node->right = tree_init(student);  // Используйте tree_init
//            return;
//        }
//        node->add_node(node->right, student);
//        return;
//    } else {
//        if (node->cnt % 1 == 0) {
//            // Выделяем дополнительное место при необходимости
//            node->student = realloc(node->student, (node->cnt + 1) * sizeof(Student*));
//        }
//
//        node->cnt++;
//        node->student[node->cnt - 1] = student;
//    }
//}

void tree_add_node(Tree* node, Student* student) {
    if (strcmp(node->student[node->cnt - 1]->surname, student->surname) < 0) {
        if (node->left == NULL) {
            node->left = tree_init(student);  // Используйте tree_init
            return;
        }
        node->add_node(node->left, student);
        return;
    }

    if (strcmp(node->student[node->cnt - 1]->surname, student->surname) > 0) {
        if (node->right == NULL) {
            node->right = tree_init(student);  // Используйте tree_init
            return;
        }
        node->add_node(node->right, student);
        return;
    }

    // Создайте новый объект Student и скопируйте данные
    Student* newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newStudent->surname, student->surname);
    strcpy(newStudent->name, student->name);
    strcpy(newStudent->gender, student->gender);
    newStudent->age = student->age;
    newStudent->group = student->group;
    newStudent->math_mark = student->math_mark;
    newStudent->phys_mark = student->phys_mark;
    newStudent->chemistry_mark = student->chemistry_mark;
    newStudent->printStudent = student->printStudent;

    // Увеличиваем размер массива и сохраняем новый объект
    node->cnt++;
    node->student[node->cnt - 1] = newStudent;
}

void tree_print(Tree* node) {
    if (node == NULL) {
        return;
    }


    for(int i = 0; i < node->cnt; i++){
        //node->student[i]->printStudent(node->student[i]);
        printf("\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
               "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
               node->student[i]->surname, node->student[i]->name, node->student[i]->gender,
               node->student[i]->age, node->student[i]->group, node->student[i]->math_mark,
               node->student[i]->phys_mark, node->student[i]->chemistry_mark);
    }
    tree_print(node->right);
    tree_print(node->left);
}

void tree_clear(Tree* node) {
    if (node->left != NULL)
        tree_clear(node->left);
    if (node->right != NULL)
        tree_clear(node->right);
    for (int i = 0; i < node->cnt; i++) {
        free(node->student[i]);
    }

    free(node->student);
    free(node);     // Освобождение самого узла
}

