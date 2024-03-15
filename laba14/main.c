//main.c
#include <stdio.h>
#include <stdlib.h>
#include "libs/File.h"
#include <string.h>
#include <time.h>


int main() {
    srand(time(NULL));
    system("chcp 65001");
    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
    ArgsForStudent* argsForStudent = malloc(sizeof(ArgsForStudent));
    const int size_stud = 10;
    List* students = List(students);
    args->list = students;
    printf("******Before******");
    student_load(students);
    for (int i = 0; i < size_stud; i++) {
        Student* student = malloc(sizeof(Student));
        student->printStudent = print_stud;
//        if (rand() % 2 == 1) {
//            strcpy(student->surname, maleSurnames[rand() % 10]);
//            strcpy(student->name, maleNames[rand() % 10]);
//            strcpy(student->gender, "Male");
//        } else {
//            strcpy(student->surname, femaleSurnames[rand() % 10]);
//            strcpy(student->name, femaleNames[rand() % 10]);
//            strcpy(student->gender, "Female");
//        }
//        args->student = student;
//        args->index = i;
//        student->age = rand() % 5 + 16;
//        student->group = rand() % 5 + 1;
//        student->math_mark = rand() % 3 + 3;
//        student->phys_mark = rand() % 3 + 3;
//        student->chemistry_mark = rand() % 3 + 3;
//        students->append(args);
//        argsForStudent->student = students->get(args);
//        student->printStudent(argsForStudent);
        //student_save(student);

    }

//    printf("\n\n******After******");
//    students->sort(args);
//    for (int i = 0; i < size_stud; i++){
//        args->index = i;
//        Student* my_very_VERY_tmp_student = students->get(args);
//        argsForStudent->student = my_very_VERY_tmp_student;
//        my_very_VERY_tmp_student->printStudent(argsForStudent);
//    }
//    students->free_list(students);
//    free(args);
//    free(argsForStudent);
//    FILE* file = fopen(filename, "r");
//    Student* student = malloc(sizeof(Student));
//
//    {
//        printf("\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
//                      "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
//                student->surname, student->name, student->gender, student->age, student->group,
//                student->math_mark, student->phys_mark, student->chemistry_mark);
//    }
//    fclose(file);
    return 0;
}
