//main.c
#include <stdio.h>
#include <stdlib.h>
#include "libs/File.h"
#include <string.h>
#include <time.h>


int main() {
//    srand(time(NULL));
//    //system("chcp 65001");
//    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
//    List* students = List(students);
//    args->list = students;
//    printf("******Before******");
//    students_load(students);
//    students->print(students);
//    printf("\n\n******After******");
//    students->sort(args);
//
//    students->print(students);
//    int checker;
//    printf("Do you want save this list in file '%s'? [0-Yep  /  1-Nope]: ", filename);
//    scanf_s("%d", &checker);
//    if (checker == 0){
//        students_save(students);
//    }
//    students->free_list(students);
//    free(args);
    srand(time(NULL));
    system("chcp 65001");
    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
    const int size_stud = 10;
    List* students = List(students);
    args->list = students;
    printf("******Before******");
//    for (int i = 0; i < size_stud; i++) {
//        Student* student = malloc(sizeof(Student));
//        student->printStudent = print_stud;
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
//        student->printStudent(student);
//    }
    students_load(students);
    //students_save(students);
    printf("\n\n******After******");
    students->sort(args);
//    for (int i = 0; i < size_stud; i++){
//        args->index = i;
//        Student* my_very_VERY_tmp_student = students->get(args);
//        my_very_VERY_tmp_student->printStudent(my_very_VERY_tmp_student);
//    }
    students->print(students);
    students->free_list(students);
    free(args);
    return 0;
}
