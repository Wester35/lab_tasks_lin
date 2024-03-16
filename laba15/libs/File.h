// File.h
// Created by wstr on 14.03.2024.
//

#ifndef LABA14_FILE_H
#define LABA14_FILE_H
#include "List.h"
#include <stdlib.h>
#include <string.h>

EC_char* filename;


void students_save(List*);
void students_load(List*);
//void student_load(Student*)
#endif //LABA14_FILE_H
