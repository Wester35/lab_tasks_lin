// File.c
// Created by wstr on 14.03.2024.
//

#include "File.h"


c_char* filename = "student_save.wstr";

void student_save(Student* student){
    FILE* file = fopen((c_char*) filename, "a");
    if(file == NULL){
        fprintf(stderr, "This error raised while student trying to save");
        exit(-1);
    }
    fprintf(file, "\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
           "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
           student->surname, student->name, student->gender, student->age, student->group,
           student->math_mark, student->phys_mark, student->chemistry_mark);
    fclose(file);
}

void* student_load(List* list){
    ArgsForDefs* args = malloc();
    FILE* file = fopen((c_char*) filename, "r");
    List* students = _args->list;
    Student* student = _args->student;
    while(!feof(file)){
        Student
        fscanf(file,
               "\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
               "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
               student->surname, student->name, student->gender, &student->age, &student->group,
               &student->math_mark, &student->phys_mark, &student->chemistry_mark);
        students->append(args);
    }
    fclose(file);
}
