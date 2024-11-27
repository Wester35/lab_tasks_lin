//main.c
#include <stdio.h>
#include <stdlib.h>
#include "libs/List.h"
#include <string.h>
#include <time.h>


int main() {
    srand(time(NULL));
    system("chcp 65001");
    ArgsForDefs* args = malloc(sizeof(ArgsForDefs));
    List* students = List(students);
    args->list = students;
    printf("******Before******");
    students->load_from_file(students);
    students->print(students);
    printf("\n\n******After******");
    students->sort(args);

    students->print(students);
    int checker;
    printf("Do you want save this list in file '%s'? [0-Yep  /  1-Nope]: ", filename);
    scanf_s("%d", &checker);
    if (checker == 0){
        //students_save(students);
        students->save_to_file(students);
    }
    students->free_list(students);
    free(args);
    return 0;
}
