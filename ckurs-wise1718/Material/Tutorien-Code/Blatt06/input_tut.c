#include <stdio.h>
#include <stdlib.h>
#include "input_tut.h"

int lese_int() {
    int nummer = 0;
    int ret = 0;
    char c;
    printf("Bitte gebe eine Nummer ein: ");
    while(ret == 0) {
        ret = scanf("%d%c", &nummer, &c);
        while (c != '\n' && getchar() != '\n') { };
        if (ret == 0)
            printf("\nDas war keine Nummer. Versuche es erneut: ");
    }

    return nummer;
}

char lese_char() {
    char letter = 0;
    int ret = 0;
    char c;
    printf("Bitte gebe einen Buchstaben ein: ");
    while(ret == 0) {
        ret = scanf("%c%c", &letter, &c);
        while (c != '\n' && getchar() != '\n') { };
        if (ret == 0)
            printf("\nDas war kein Buchstabe. Versuche es erneut: ");
    }

    return letter;
}

void print_array(int *array, int laenge) {
    if (laenge > 0) {
        printf("%d", array[0]);
        for (int i=1; i < laenge; i++) {
            printf(", %d", array[i]);
        }
    }
    printf("\n");
}

void print_chars(char *array, int laenge) {
    if (laenge > 0) {
        printf("%c", array[0]);
        for (int i=1; i < laenge; i++) {
            printf(", %c", array[i]);
        }
    }
    printf("\n");
}
