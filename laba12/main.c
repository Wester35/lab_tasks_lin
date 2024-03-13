//main.c
#include <stdio.h>
#include <stdlib.h>
#include "libs/List.h"
#include <string.h>
#include <time.h>


int main() {
    srand(time(NULL));
    ArgsForDefs* _args = malloc(sizeof(ArgsForDefs));
    const int size_stud = 10;
    List* students = List(students);
    _args->list = students;
    printf("******Before******");
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
        _args->student1 = student;
        _args->index = i;
        student->age = rand() % 5 + 16;
        student->group = rand() % 5 + 1;
        student->math_mark = rand() % 3 + 3;
        student->phys_mark = rand() % 3 + 3;
        student->chemistry_mark = rand() % 3 + 3;
        students->append(_args);
        student->printStudent(students->get(_args));
    }

    printf("\n\n******After******");
    students->sort(_args);
    for (int i = 0; i < size_stud; i++){
        _args->index = i;
        Student* my_very_VERY_tmp_student = students->get(_args);
        my_very_VERY_tmp_student->printStudent(my_very_VERY_tmp_student);
    }
    students->free_list(_args);
    free(_args);
    return 0;
}

