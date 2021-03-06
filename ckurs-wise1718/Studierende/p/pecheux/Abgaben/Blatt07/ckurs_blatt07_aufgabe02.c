#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input3.h"

/* Die Konstanten:
 *  int MAX_LAENGE_STR - die maximale String Länge
 *  int MAX_LAENGE_ARR - die maximale Array Länge
 *  sind input3.c auf jeweils 255 und 100 definiert
 */

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Aufruf: %s <anzahl> <bundesland>\n", argv[0]);
        printf("Beispiel: %s 100 Bayern\n", argv[0]);
        printf("Klein-/Großschreibung beachten!\n");
        exit(1);
    }
    int anzahl = atoi(argv[1]); // in the exqmpl: 100
    char *bundesland = argv[2]; // in the example: Bayern

    // Statisch allokierter Speicher
    char staedte[MAX_LAENGE_ARR][MAX_LAENGE_STR];
    char laender[MAX_LAENGE_ARR][MAX_LAENGE_STR];
    int bewohner[MAX_LAENGE_ARR];

    int len = read_file("staedte.csv", staedte, laender, bewohner);

    int impl = 0;// how many mach are there

    //char *arrayOfStrResult[] = malloc (MAX_LAENGE_ARR * sizeof(char*)) ;
    char* arrayOfStrResult[MAX_LAENGE_ARR];

    for (int i =0; i<79; i++){
      if (strncmp( laender[i], bundesland, MAX_LAENGE_STR)==0 && bewohner[i] >= anzahl){
        arrayOfStrResult[impl] = malloc (MAX_LAENGE_STR * sizeof(char)) ;
        snprintf(arrayOfStrResult[impl],MAX_LAENGE_STR,"Die Stadt %s hat %d Einwohner.",staedte[i],bewohner[i]);
        impl++;
      }
    }
    write_file( arrayOfStrResult, impl);
    for (int i =0; i<impl; i++){
        free (arrayOfStrResult[i]);
      }
    //free (arrayOfStrResult);
    return 0;
}
