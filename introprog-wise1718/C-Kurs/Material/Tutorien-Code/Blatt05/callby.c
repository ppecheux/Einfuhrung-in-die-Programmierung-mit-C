#include <stdio.h>
#include <stdlib.h>

// Call-by-value
int addOne(int res) {
    res = res + 2;
    return res;
}

// Call-by-ref
void addTwo(int* res) {
    *res = *res + 2;
}

int main() {
    // nur zum testen
    int resultat;
    int zahl = 9;
    resultat = addOne(zahl);
    printf("add %d\n", resultat);

    addTwo(&resultat);
    printf("addTwo %d\n", resultat);
    return 0;
}
