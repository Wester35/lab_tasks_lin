//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "tree.h"

#define Tree(student) tree_init(student)


int main() {
    srand(time(NULL));
    //system("chcp 65001");

    const int size_stud = 10;
    Student* student = malloc(sizeof(Student));
    Tree* students = Tree(student);
    printf("******Before******");

//    for (int i = 0; i < size_stud; i++) {
//        if (rand() % 2 == 1) {
//            strcpy(student->surname, maleSurnames[rand() % 10]);
//            strcpy(student->name, maleNames[rand() % 10]);
//            strcpy(student->gender, "Male");
//        } else {
//            strcpy(student->surname, femaleSurnames[rand() % 10]);
//            strcpy(student->name, femaleNames[rand() % 10]);
//            strcpy(student->gender, "Female");
//        }
//
//        student->age = rand() % 5 + 16;
//        student->group = rand() % 5 + 1;
//        student->math_mark = rand() % 3 + 3;
//        student->phys_mark = rand() % 3 + 3;
//        student->chemistry_mark = rand() % 3 + 3;
//
//        students->add_node(students, student);
//        free(student);
//    }
    for (int i = 0; i < size_stud; i++) {
        if (rand() % 2 == 1) {
            strcpy(student->surname, maleSurnames[rand() % 10]);
            strcpy(student->name, maleNames[rand() % 10]);
            strcpy(student->gender, "Male");
        } else {
            strcpy(student->surname, femaleSurnames[rand() % 10]);
            strcpy(student->name, femaleNames[rand() % 10]);
            strcpy(student->gender, "Female");
        }

        student->age = rand() % 5 + 16;
        student->group = rand() % 5 + 1;
        student->math_mark = rand() % 3 + 3;
        student->phys_mark = rand() % 3 + 3;
        student->chemistry_mark = rand() % 3 + 3;

        students->add_node(students, student);
        //free(student);
    }

    students->print(students);
    free(student);
    students->clear(students);
    return 0;
}

