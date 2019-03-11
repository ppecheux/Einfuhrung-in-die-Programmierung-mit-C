#include <stdio.h>
#include <stdlib.h>
#include "string.h" // Stringfunktionen importieren

int main() {
    char* string1 = "Hello World!";
    char* string2 = "hello world!";
    char* string3 = "Heklo World!";
    char* string4 = "Hemlo World!";

    int laenge = strlen(string1);
    int vergleich;
    printf("Laenge des String: %d\n\n", laenge);

    printf("0  -> Gleicher String\n");
    printf("<0 -> Erster unterschiedlicher Charakter in string1 hat einen größeren ASCII Wert als der in string2\n");
    printf(">0 -> Erster unterschiedlicher Charakter in string1 hat einen kleineren ASCII Wert als der in string2\n\n");

    vergleich = strcmp(string1, string1);
    printf("'%s' == '%s' = %d\n", string1, string1, vergleich);

    vergleich = strcmp(string1, string3);
    printf("'%s' == '%s' = %d\n", string1, string3, vergleich);

    vergleich = strcmp(string1, string4);
    printf("'%s' == '%s' = %d\n", string1, string4, vergleich);

    vergleich = strcmp(string1, string2);
    printf("'%s' == '%s' = %d\n", string1, string2, vergleich);
    return 0;
}
