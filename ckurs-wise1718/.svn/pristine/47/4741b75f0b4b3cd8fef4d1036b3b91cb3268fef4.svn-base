#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    char *string = "hello world!";
    char string2[3];
    int nummer = 3;

    printf("nummer = %d\n", nummer);

    // ACHTUNG:
    // string2 ist kleiner als string
    // strcpy kopiert "hello world" in den Bereich,
    // der nicht mehr zur variable "string" gehört.
    strcpy(string2, string);
    printf("string2 = %s\n", string2);
    printf("nummer = %d\n", nummer);
}
