// File.c
// Created by wstr on 14.03.2024.
//

#include "File.h"


c_char* filename = "student_save.bin";


//void students_save(List* list) {
//    FILE* file = fopen("student_save.bin", "ab"); // Открываем файл для добавления данных в конец
//    if (file == NULL) {
//        fprintf(stderr, "Failed to open file for writing.\n");
//        exit(EXIT_FAILURE);
//    }
//
//    for (int i = 0; i < list->size; i++) {
//        ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
//        args->index = i;
//        Student* student = list->get(args);
//
//
//        fwrite(student, sizeof(Student), 1, file);
//
//        free(args);
//    }
//
//    fclose(file);
//}

void students_save(List* list){
    FILE* file;
    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
    args->list = list;
    Student* student;
    file = fopen("student_save.binary", "wb");
    if(file == NULL){
        fprintf(stderr, "This error raised while student trying to save");
        exit(-1);
    }
    for (int i = 0; i < list->size; i++){
        args->index = i;
        student = list->get(args);
        fwrite(student, sizeof(Student), 1, file);
    }


    free(args);
    fclose(file);
}

//void student_load(Student* student){
//    FILE* file;
//    student = malloc(sizeof(Student));
//    file = fopen("student_save.bin", "rb");
//    if(file == NULL){
//        fprintf(stderr, "This error raised while student trying to save");
//        exit(-1);
//    }
//    size_t tmp_len = strlen(student->surname);
//    fread(
//                &student->surname,
//                sizeof(char),
//                20,
//                file
//    );
//    tmp_len = strlen(student->name);
//    fread(
//            &student->name,
//                sizeof(char),
//                20,
//                file
//                );
//    tmp_len = strlen(student->gender);
//    fread(
//                &student->gender,
//                sizeof(char),
//                6,
//                file
//        );
//    fread(
//                &(student->age),
//                sizeof(int),
//                4,
//                file
//        );
//    fread(
//                &(student->group),
//                sizeof(int),
//                4,
//                file
//        );
//    fread(
//                &(student->math_mark),
//                sizeof(int),
//                4,
//                file
//        );
//    fread(
//                &(student->phys_mark),
//                sizeof(int),
//                4,
//                file
//        );
//    fread(
//                &(student->chemistry_mark),
//                sizeof(int),
//                4,
//                file
//        );
//    fread(
//                &(student->printStudent),
//                sizeof(int),
//                2,
//                file
//        );
//    fclose(file);
//}

void students_load(List* list) {
    FILE* file = fopen(filename, "rb");
    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
    args->list = list;
//    while (1) {
//        Student* student = malloc(sizeof(Student));
//        args->student = student;
//        // Читаем данные студента из файла
//        size_t items_read = fread(student->surname, sizeof(char), 20, file);
//        if (items_read != 20) break;
//
//        fread(student->name, sizeof(char), 20, file);
//        fread(student->gender, sizeof(char), 6, file);
//        fread(&(student->age), sizeof(int), 1, file);
//        fread(&(student->group), sizeof(int), 1, file);
//        fread(&(student->math_mark), sizeof(int), 1, file);
//        fread(&(student->phys_mark), sizeof(int), 1, file);
//        fread(&(student->chemistry_mark), sizeof(int), 1, file);
//
//        // Добавляем студента в список
//        list->append(args);
//    }
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < 10; i++){
        Student* student = malloc(sizeof(Student));
        fread(student, sizeof(Student), 1, file);
        args->student = student;
        list->append(args);
    }
    fclose(file);


    free(args);
}

//void students_load(List* list){
//    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
//    FILE* file = fopen((c_char*) filename, "r");
//    args->list = list;
//    while(!feof(file)){
//        Student* student = malloc(sizeof(Student));
//        fscanf(file,
//               "\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
//               "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
//               student->surname, student->name, student->gender, &student->age, &student->group,
//               &student->math_mark, &student->phys_mark, &student->chemistry_mark);
//        stud_count++;
//        args->student = student;
//        list->append(args);
//    }
//    free(args);
//    fclose(file);
//}