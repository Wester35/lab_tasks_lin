// File.c
// Created by wstr on 14.03.2024.
//

#include "File.h"


c_char* filename = "student_save.sav";


void students_save(List* list){
    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
    args->list = list;
    FILE* file = fopen((c_char*) filename, "a");
    for (int i = 0; i < list->size; i++){
        args->index = i;
        Student* student = list->get(args);
        if(file == NULL){
            fprintf(stderr, "This error raised while student trying to save");
            exit(-1);
        }
        fprintf(file, "\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
               "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
               student->surname, student->name, student->gender, student->age, student->group,
               student->math_mark, student->phys_mark, student->chemistry_mark);

    }
    free(args);
    fclose(file);
}

void students_load(List* list){
    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
    FILE* file = fopen((c_char*) filename, "r");
    args->list = list;
    while(!feof(file)){
        Student* student = malloc(sizeof(Student));
        fscanf(file,
               "\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
               "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
               student->surname, student->name, student->gender, &student->age, &student->group,
               &student->math_mark, &student->phys_mark, &student->chemistry_mark);
        stud_count++;
        args->student = student;
        list->append(args);
    }
    free(args);
    fclose(file);
}
