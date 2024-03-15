// File.h
// Created by wstr on 14.03.2024.
//

#ifndef LABA14_FILE_H
#define LABA14_FILE_H
#include "List.h"
#include <stdlib.h>
#include <string.h>

EC_char* filename;

void student_save(Student*);
void student_load(List*);
#endif //LABA14_FILE_H
