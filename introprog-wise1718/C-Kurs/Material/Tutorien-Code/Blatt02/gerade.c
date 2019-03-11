#include <stdio.h>
#include <stdlib.h>

int main() {
    // Erkläre das Prinzip der Zuweisung:
    int nummer = 10; // Teste mit mehreren Zahlen

    // Erläuterung des modulo Operators
    /*
     * Wie debuggt man einen Fehler mit printf?
     *
     *  int zwischen = nummer % 2;
     *  if (zwischen == 1) {
     *      printf("Zahl ist gerade!\n");
     *      printf("Zwischenergebnis %d\n", zwischen);
     *  } else {
     *      printf("Zahl ist ungerade!\n");
     *  }
     */
    if (nummer % 2 == 0) {
        printf("Zahl ist gerade!\n");
    } else {
        printf("Zahl ist ungerade!\n");
    }
    return 0;
}
