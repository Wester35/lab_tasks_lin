//main.c
#include <stdio.h>
#include <stdlib.h>
#include "libs/List.h"
#include <string.h>
#include <time.h>

typedef struct ArgsForDefs{
    List* list;
    Student* student;
    int index;
} ArgsForDefs;

int main() {
    srand(time(NULL));

    const int size_stud = 10;
    List* students = List(students);
    ArgsForDefs* argsForDefs = malloc(sizeof(ArgsForDefs));
    void* args_dor_def[3];
    printf("******Before******");
    argsForDefs->list=students;
    for (int i = 0; i < size_stud; i++) {
        Student* student = malloc(sizeof(Student));
        student->printStudent = print_stud;
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
        students->append(students, student);
        student->printStudent(students->get(students, i));
    }

    printf("\n\n******After******");
    students->sort(students, size_stud);
    for (int i = 0; i < size_stud; i++){
        Student* my_very_VERY_tmp_student = students->get(students, i);
        my_very_VERY_tmp_student->printStudent(my_very_VERY_tmp_student);
    }
    students->free_list(students);
    return 0;
}

