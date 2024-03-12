// Student.h
// Created by Wstr35 on 12.03.2024.
//

#ifndef LABA12_STUDENT_H
#define LABA12_STUDENT_H
#include <stdio.h>


extern const char femaleNames[10][20];
extern const char maleNames[10][20];
extern const char femaleSurnames[10][20];
extern const char maleSurnames[10][20];

typedef struct Student {
    char surname[20];
    char name[20];
    char gender[6];
    int age;
    int group;
    int math_mark;
    int phys_mark;
    int chemistry_mark;
    void (*printStudent)(struct Student* student);
} Student;

void print_stud(Student* student);

#endif //LABA12_STUDENT_H
