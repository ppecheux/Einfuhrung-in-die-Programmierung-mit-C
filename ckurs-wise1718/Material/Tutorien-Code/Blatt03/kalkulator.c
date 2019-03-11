#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    int ergebnis = a + b;
    return ergebnis;
}
int sub(int a, int b) {
    int ergebnis = a - b;
    return ergebnis;
}
// positive ganzzahlige Potenz
int potenz(a, int b) {
    int ergebnis = a;
    for (int i=0; i<b-1; i++) {
        ergebnis = ergebnis * a;
    }
    return ergebnis;
}

int main() {
    int zahla = 10;
    int zahlb = 3;
    int resultat; 

    resultat = add(zahla, zahlb);
    printf("Addition: %d\n", resultat);
    resultat = sub(zahla, zahlb);
    printf("Subtraktion: %d\n", resultat);
    resultat = potenz(zahla, zahlb);
    printf("Potenz: %d\n", resultat);
    return 0;
}
