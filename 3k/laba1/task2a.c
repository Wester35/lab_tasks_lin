#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define ERROR_INVALID_ARGS 1
#define ERROR_FILE_NOT_FOUND 2
#define ERROR_UNKNOWN_MODE 3


void print_help() {
    printf("Использование: <исполняемый файл> [ПАРАМЕТРЫ]\n");
    printf("Параметры:\n");
    printf(" -i <входной файл>      Указываю входной файл\n");
    printf(" -o <выходной файл>     Укажите выходной файл\n");
    printf(" -s <shift>             Укажите сдвиг для шифра Цезаря\n");
    printf(" -d                     Режим дешифрования (по умолчанию используется шифрование)\n");
    printf(" -h, --help             Показать это справочное сообщение\n");
}

void caesars_cipher(FILE *input, FILE *output, int shift, int decrypt) {
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            if (decrypt) {
                ch = base + ((ch - base - shift + 26) % 26);
            } else {
                ch = base + ((ch - base + shift) % 26);
            }
        }
        fputc(ch, output);
    }
}

int main(int argc, char *argv[]) {
    char *input_filename = NULL;
    char *output_filename = NULL;
    int shift = 0, decrypt = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            input_filename = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_filename = argv[++i];
        } else if (strcmp(argv[i], "-s") == 0 && i + 1 < argc) {
            shift = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-d") == 0) {
            decrypt = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return SUCCESS;
        } else {
            fprintf(stderr, "Error: Invalid arguments\n");
            print_help();
            return ERROR_INVALID_ARGS;
        }
    }

    if (!input_filename || !output_filename || shift == 0) {
        fprintf(stderr, "Error: Missing required arguments\n");
        print_help();
        return ERROR_INVALID_ARGS;
    }


    
    FILE *finput = fopen(input_filename, "r");
    FILE *foutput = fopen(output_filename, "w");
    caesars_cipher(finput, foutput, shift, decrypt);
    fclose(finput);
    fclose(foutput);
    return 0;
}