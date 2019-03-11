#include <stdio.h>
#include <stdlib.h>

int main() {
   // definiere eine Zahl
   printf("Variable: zahl\n");
   int zahl = 3;
   printf("Wert: %d\n", zahl);
   printf("Adresse: %p\n\n", &zahl);

   // definiere einen Pointer auf diese Zahl
   printf("Variable: zweite_zahl\n");
   int *zweite_zahl = &zahl;
   printf("Wert: %d\n", *zweite_zahl);
   printf("Adresse: %p\n\n", zweite_zahl);

   // Wenn nun die originale Zahl geändert wird,
   // ändert sich auch die zweite Zahl
   printf("Variable: zweite_zahl\n");
   zahl = 7;
   printf("Wert: %d\n", *zweite_zahl);
   printf("Adresse: %p\n\n", zweite_zahl);

   // und genauso umgekehrt
   printf("Variable: zahl\n");
   *zweite_zahl = 9;
   printf("Wert: %d\n", zahl);
   printf("Adresse: %p\n\n", &zahl);
}
