#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    char* hello = "Hello World!";
    int laenge = strlen(hello);
    char* string = (char*) malloc((laenge+1) * sizeof(char));

    strncpy(string, hello, laenge);
    string[laenge] = '\0';

    printf("%s\n", string);
}
