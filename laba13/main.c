//main.c
#include <stdio.h>
#include <stdlib.h>
#include "libs/List.h"
#include <string.h>
#include <time.h>
//#define for_in(iterations) \
//{ \
//    typeof(iterations) _iterations = (iterations); \
//    for(int i = 0; i < _iterations; i++) {  \
//}
//#define for_in_end }
#define memory_ext(size) malloc(sizeof(size))

int main() {
    srand(time(NULL));
    system("chcp 65001");
    ArgsForDefs* args = memory_ext(ArgsForDefs);
    ArgsForStudent* argsForStudent = malloc(sizeof(ArgsForStudent));
    const int size_stud = 10;
    List* students = List(students);
    args->list = students;
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
        args->student = student;
        args->index = i;
        student->age = rand() % 5 + 16;
        student->group = rand() % 5 + 1;
        student->math_mark = rand() % 3 + 3;
        student->phys_mark = rand() % 3 + 3;
        student->chemistry_mark = rand() % 3 + 3;
        students->append(args);
        argsForStudent->student = students->get(args);
        student->printStudent(argsForStudent);
    }

    printf("\n\n******After******");
    students->sort(args);
    for (int i = 0; i < size_stud; i++){
        args->index = i;
        Student* my_very_VERY_tmp_student = students->get(args);
        argsForStudent->student = my_very_VERY_tmp_student;
        my_very_VERY_tmp_student->printStudent(argsForStudent);
    }
    students->free_list(students);
    free(args);
    free(argsForStudent);
    return 0;
}
