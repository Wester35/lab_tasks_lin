#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>  
#include <unistd.h>  
#include <errno.h> 

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

void caesars_cipher(int finput, int foutput, int shift, int decrypt) {
    char ch;
    ssize_t bytes_read;
    while ((bytes_read = read(finput, &ch, 1)) > 0) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            if (decrypt) {
                ch = base + ((ch - base - shift + 26) % 26);
            } else {
                ch = base + ((ch - base + shift) % 26);
            }
        }
        write(foutput, &ch, 1);
    }

    if (bytes_read < 0) {
        perror("Error reading input file");
        exit(ERROR_FILE_NOT_FOUND);
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

    int finput = open(input_filename, O_RDONLY);
    if (finput < 0) {
        perror("Error opening input file");
        return ERROR_FILE_NOT_FOUND;
    }

    int foutput = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (foutput < 0) {
        perror("Error opening output file");
        close(finput);
        return ERROR_FILE_NOT_FOUND;
    }

    caesars_cipher(finput, foutput, shift, decrypt);

    close(finput);
    close(foutput);

    return SUCCESS;
}
