#include <stdio.h>
#include <stdlib.h>

int main() {
    int hoehe = 3; 
    int laenge = 10;
    int zahl; // Warum muss diese Zahl nicht initialisiert werden?

    for (int i=0; i<hoehe; i++) {
        for (int j=0; j<laenge; j++) {
            zahl = i*hoehe + j;
            if (zahl < 10) { // Im zweiten Schritt
                printf(" ");
            }
            printf("%d ", zahl);
        }
        printf("\n");
    }
}
