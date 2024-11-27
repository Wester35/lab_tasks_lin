// Student.h
// Created by Wstr35 on 12.03.2024.
//

#ifndef LABA12_STUDENT_H
#define LABA12_STUDENT_H
#include <stdio.h>
#define Class typedef struct
#define c_char const char
#define EC_char extern const char


EC_char femaleNames[10][20];
EC_char maleNames[10][20];
EC_char femaleSurnames[10][20];
EC_char maleSurnames[10][20];

Class Student {
    char surname[20];
    char name[20];
    char gender[6];
    int age;
    int group;
    int math_mark;
    int phys_mark;
    int chemistry_mark;
    void* (*printStudent)(void*);
} Student;

Class ArgsForStudent{
    Student* student;
} ArgsForStudent;


void* print_stud(void*);

#endif //LABA12_STUDENT_H
