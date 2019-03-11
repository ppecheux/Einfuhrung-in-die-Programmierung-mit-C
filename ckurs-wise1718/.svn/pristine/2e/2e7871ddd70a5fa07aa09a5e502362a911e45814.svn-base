#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int fak(int zahl) {
    if (zahl <= 1) {
        return 1;
    }
    return zahl * fak(zahl-1);
}

int main() {
    int n = lese_int();
    int resultat;
    resultat = fak(n);

    printf("%d\n", resultat);
    return 0;
}
