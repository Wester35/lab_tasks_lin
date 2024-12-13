#include <stdio.h>
#include <stdlib.h>

#define _ int
#define __ main()
#define ___ {
#define ____ }
#define _____ const
#define ______ char
#define _______ *
#define ________ FILE
#define _________ fopen
#define __________ "task5.c"
#define ___________ ==
#define ____________ NULL
#define _____________ perror
#define ______________ return
#define _______________ EXIT_FAILURE
#define ________________ printf
#define _________________ "\n\n"
#define __________________ ch
#define ___________________ fgetc
#define ____________________ putchar
#define _____________________ fclose
#define ______________________ EXIT_SUCCESS

_ __ ___
    _____ ______ _______ filename = __________;
    ________ *file = _________(filename, "r");

    if (file ___________ ____________) {
        _____________("Ошибка открытия файла");
        ______________ _______________;
    }

    ________________("%s" _________________, filename);

    ______ __________________;
    while ((__________________ = ___________________(file)) != EOF) {
        ____________________(__________________);
    }

    _____________________(file);
    ______________ ______________________;
____
