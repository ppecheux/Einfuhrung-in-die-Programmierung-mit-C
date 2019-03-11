#include <stdio.h>
#include <stdlib.h>
#include "input_tut.h"

int main() {
    printf("Wieviele Buchstaben?\n");
    int size = lese_int();

    printf("Nenne bitte die Buchstaben.\n");
    char *array = (char*) malloc(size * sizeof(char));
    for (int i=0; i<size; i++) {
        array[i] = lese_char();
    }

    printf("Das Ergebnis ist:\n");
    print_chars(array, size);
    free(array);
}
