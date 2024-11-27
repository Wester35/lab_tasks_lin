// Student.c
// Created by Wstr35 on 12.03.2024.
//

#include "Student.h"

c_char femaleNames[10][20] = {
        "Natasha",
        "Ilya",
        "Sasha",
        "Valya",
        "Buzya",
        "Maria",
        "Olga",
        "Anna",
        "Tatiana",
        "Yulia"
};

c_char maleNames[10][20] = {
        "Masha",
        "Artem",
        "Vasya",
        "Kuzya",
        "Misha",
        "Dmitry",
        "Ivan",
        "Alexey",
        "Sergei",
        "Pavel"
};

c_char femaleSurnames[10][20] = {
        "Ivanova",
        "Sidorova",
        "Popova",
        "Vasilieva",
        "Novikova",
        "Petrova",
        "Smirnova",
        "Kuznetsova",
        "Mikhailova",
        "Fedorova"
};

c_char maleSurnames[10][20] = {
        "Petrov",
        "Smirnov",
        "Kuznetsov",
        "Mikhailov",
        "Fedorov",
        "Ivanov",
        "Sidorov",
        "Popov",
        "Vasiliev",
        "Novikov"
};

void* print_stud(void* args){
    ArgsForStudent* _args = args;
    Student* student = _args->student;
    printf("\n\nSurname: %s\nName: %s\nGender: %s\nAge: %d\n"
           "Group: %d\nMath mark: %d\nPhysic mark: %d\nChemistry mark: %d\n",
           student->surname, student->name, student->gender, student->age, student->group,
           student->math_mark, student->phys_mark, student->chemistry_mark);
    return NULL;
}