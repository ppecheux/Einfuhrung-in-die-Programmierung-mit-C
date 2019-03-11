#include <stdio.h>
#include <stdlib.h>

int main() {
    char string[13];
    // Die dynamische Variante:
    //  int laenge = 13;
    //  char* string = (char*) malloc(laenge * sizeof(char));

    string[0] = 'h';
    string[1] = 'e';
    string[2] = 'l';
    string[3] = 'l';
    string[4] = 'o';
    string[5] = ' ';
    string[6] = 'w';
    string[7] = 'o';
    string[8] = 'r';
    string[9] = 'l';
    string[10] = 'd';
    string[11] = '!';
    string[12] = '\0'; // Endzeichen für Strings

    // Dasselbe wie:
    // char string[] = "hello world!";
    // char string[20] = "hello world!";

    printf("String '%s'\n", string);
    printf("String '%s'\n", &(string[6])); // Gebe String ab Adresse 6 aus.

    string[5] = '\0'; // Versetzen des Terminations Zeichen
    printf("String '%s'\n", string);
    return 0;
}
