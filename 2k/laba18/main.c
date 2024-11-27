#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>


int main() {
    int array_size = 255, count = 0, check = 0;

    wchar_t* arr = malloc(sizeof(wchar_t) * array_size);

    fgetws(arr, array_size, stdin);

    if (wcslen(arr) > 4 && arr[3] != L'\n') {
        check++;
        wchar_t* context = NULL;
        wchar_t* words = wcstok_s(arr, L" ,.?!", &context);
        while (words) {
            if (wcslen(words) == 3)
                count++;
            words = wcstok_s(NULL, L" ,.?!", &context);
        }
    } else {
        count++;
        check++;
    }

    if ((wcslen(arr) == 3) && (check == 0))
        count++;


    wprintf(L"The number of words with a length of 3: %d\n", count);

    free(arr);

    return 0;
}