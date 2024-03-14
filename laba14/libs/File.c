//
// Created by wstr on 14.03.2024.
//

#include "File.h"

void student_save(Student* student){
    FILE* file;

    file = fopen("student_save.wstr", "a");
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
