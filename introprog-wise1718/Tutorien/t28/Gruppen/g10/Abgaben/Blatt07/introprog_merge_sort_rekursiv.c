/* === INTROPROG ABGABE ===
 * Blatt 7, Aufgabe 1
 * Tutorium: t28
 * Gruppe: g10
 * Gruppenmitglieder:
 *  - Pecheux Pierre Louis
 *  - gruppmitglieder
 * ========================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "introprog_input_merge_sort.h"

/*
  Diese Funktion fügt zwei bereits sortierte Arrays
  zu einem sortierten Array zusammen

    array : Pointer auf das Array
    first : Index des ersten Elements (Beginn) des (Teil-)Array
    middle: Index des mittleren Elements des (Teil-)Array
    last  : Index des letzten Elements(Ende) des (Teil-)Array
*/
void merge(int* array, int first, int middle, int last)
{
  int *hArray= malloc((last+1)*sizeof(int*));
  int hfirst=first;
  int hmiddle=middle+1;
  int i=0;


  while(hfirst<=middle&&hmiddle<=last){
    if(array[hfirst]<=array[hmiddle]){
      hArray[i]=array[hfirst];
      ++hfirst;
    }
    else{
      hArray[i]=array[hmiddle];
      ++hmiddle;
    }
    ++i;
  }
  while(hfirst<=middle){
    hArray[i]=array[hfirst];
    ++hfirst;
    ++i;
  }
  while(hmiddle<=last){
    hArray[i]=array[hmiddle];
    ++hmiddle;
    ++i;
  }

  int j=0;

  while(j<i){
    array[first+j]=hArray[j];
    ++j;
  }

  free(hArray);

}

/*
  Diese Funktion implementiert den rekursiven Mergesort
  Algorithmus  auf einem Array. Sie soll analog zum Pseudocode
  in Listing 1 implementiert werden.

    array: Pointer auf das Array
    first: Index des ersten Elements des (Teil-)Array
    last:  Index des letzten Elements des (Teil-)Array
*/
void merge_sort(int* array, int first, int last)
{
  if(first<last){
    int middle = (int)(((first+last)/2));
    merge_sort(array,first,middle);
    merge_sort(array,middle+1,last);
    merge(array,first,middle,last);
  }
}

/*
Hauptprogramm.

Liest Integerwerte aus einer Datei und gibt diese sortiert
im selben Format über die Standardausgabe wieder aus.

Aufruf: ./introprog_merge_sort_rekursiv <maximale anzahl>  <dateipfad>
*/
int main (int argc, char *argv[])
{
    if (argc!=3){
        printf ("usage: %s <maximale anzahl>  <dateipfad>\n", argv[0]);
        exit(2);
    }


    int *array = malloc(atoi(argv[1])*sizeof(int*));

    // Hier array initialisieren
    for(int i=0;i<atoi(argv[1]);++i){
      array[i]=0;
    }

    int len = read_array_from_file(array, atoi(argv[1]), argv[2]);

    printf("Eingabe:\n");
    print_array(array, len);

    // HIER Aufruf von "merge_sort()"
    merge_sort(array,0,len-1);

    printf("Sortiert:\n");
    print_array(array, len);

    free(array);

    return 0;
}
