#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    char *protagonist = "Jim Knopf";
    char *piraten  = "die Wilde";
    int id = 13;
    
    const size_t kapazitaet = 100 * sizeof(char);

    char* string = (char*) malloc(kapazitaet);

    snprintf(string, kapazitaet, "%s und %s %d", protagonist, piraten, id);

    printf("%s\n", string);
}
