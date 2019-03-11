#include <stdio.h>
#include <stdlib.h>

int main() {
    // Erkläre das Prinzip der Zuweisung:
    int nummer = 10;
    // Was ist der Unterschied zwischen Deklaration:
    int ergebnis;
    // und Initialiserung?
    ergebnis = 1;
    // Was sagt gcc, wenn man die Initialisierung weglässt?

    printf("Was ist die Fakultät von %d?\n", nummer);

    // Erkläre erst die Fakultät an der Tafel: n*n-1*...*1
    for (int i=1; i<=nummer; i++) { // Erkläre i++ ist gleich i = i + 1
        ergebnis = ergebnis * i;
        printf("- %d\n", ergebnis);
    }

    printf("Ergebnis = %d\n", ergebnis);

    // Es gibt mehrere Wege zum Ziel:
    ergebnis = 1;
    while(nummer > 0) {
        ergebnis = ergebnis * nummer;
        nummer--;
        printf("- %d\n", ergebnis);
    }
    // Was ist der Unterschied?

    printf("Ergebnis = %d\n", ergebnis);
}
