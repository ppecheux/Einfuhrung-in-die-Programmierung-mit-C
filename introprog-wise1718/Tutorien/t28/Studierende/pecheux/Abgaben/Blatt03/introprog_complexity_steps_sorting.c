/* === INTROPROG ABGABE ===
 * Blatt 3, Aufgabe 1
 * Tutorium: t28
 * Abgabe von: PierreLouis Pecheux
 * ========================
 */

#include <stdio.h>
#include <stdlib.h>
#include "introprog_complexity_steps_input.h"

const int MAX_VALUE = 5000000;

void count_sort_calculate_counts(int input_array[], int len, int count_array[], int* befehle) {
    //muss implementiert werden
    (*befehle)++;//int j = 0
    for(int j =0 ; j<len; j++){
      (*befehle)++;//++j
      (*befehle)++;//j<=n
      count_array[input_array[j]]++;(*befehle)++;
    }
    (*befehle)++;//j<=n
}

void count_sort_write_output_array(int output_array[], int len, int count_array[], int* befehle) {
    //muss implementiert werden
    int k=0;(*befehle)++;//int k = 0
    (*befehle)++;//int j = 0
    for(int j =0;j<=MAX_VALUE;j++){
      (*befehle)++;//++j
      (*befehle)++;//j<=n
      (*befehle)++;//int i = 0
      for(int i = 0; i<count_array[j];i++){
        (*befehle)++;//++i
        (*befehle)++;//i<=n
        output_array[k]=j;(*befehle)++;//int k++
        k++;(*befehle)++;//int k++
      }
      (*befehle)++;//i<=n
    }
    (*befehle)++;//j<=n
}

void count_sort(int array[], int len, int* befehle) {
    //muss implementiert werden
    //1. Erstelle zunächst mittels malloc ein Array
    //zum Zählen der Häufigkeiten verschiedenerWerte.
    int* count_array = malloc(sizeof(int) * (MAX_VALUE+1));(*befehle)++;

    //initialization von count_array
    (*befehle)++;//i=0
    for(int i=0;i<=MAX_VALUE;i++){
      (*befehle)++;//++i
      (*befehle)++;//i<=n
      count_array[i]=0;(*befehle)++;
    }

    count_sort_calculate_counts(array, len, count_array, befehle);
    count_sort_write_output_array(array,len,count_array,befehle);
    (*befehle)++;//i<=n

    free (count_array);(*befehle)++;
}


void insertion_sort(int array[], int len, int* befehle) {
    //muss implementiert werden
    int key,i;
    (*befehle)++;//j=1
  for(int j =1; j<len; j++){
    (*befehle)++;//++j
    (*befehle)++;//j<=n
    key = array[j];(*befehle)++;
    i= j-1;(*befehle)++;
    while (i>=0 && array[i]>key){
      (*befehle)++;//i>=0
      (*befehle)++;//arrayi>key
      array[i+1] = array[i];(*befehle)++;
      i--;(*befehle)++;
    }
    (*befehle)++;//i>=0
    array[i+1]= key;(*befehle)++;
  }
  (*befehle)++;//j<=n
}


int main(int argc, char *argv[]) {

    const int WERTE[] = {10000,20000,30000,40000,50000};
    const int LEN_WERTE = 5;
    const int LEN_ALGORITHMEN = 2;

    int rc = 0;
    long befehle_array[LEN_ALGORITHMEN][LEN_WERTE];
    double laufzeit_array[LEN_ALGORITHMEN][LEN_WERTE];

    for(int j = 0; j < LEN_WERTE; ++j)
    {
        int n = WERTE[j];

        //reserviere Speicher für  Arrays der Länge n
        int* array_countsort = malloc(sizeof(int) * n);
        int* array_insertionsort = malloc(sizeof(int) * n);

        //fülle array_countsort mit Zufallswerten ..
        fill_array_randomly(array_countsort, n, MAX_VALUE);
        //.. und kopiere die erzeugten Werte in das Array array_insertionsort
        copy_array_elements(array_insertionsort, array_countsort, n);

        //teste ob beide Arrays auch wirklich die gleichen Werte enthalten
        if(!check_equality_of_arrays(array_countsort, array_insertionsort, n))
        {
            printf("Die Eingaben für beide Algorithmen müssen für die Vergleichbarkeit gleich sein!\n");
            return -1;
        }

        for(int i = 0; i < LEN_ALGORITHMEN; ++i)
        {
            int anzahl_befehle = 0;

            start_timer();

            //Aufruf der entsprechenden Sortieralgorithmen
            if(i==0)
            {
                    count_sort(array_countsort, n, &anzahl_befehle);
            }
            else if(i==1)
            {
                    insertion_sort(array_insertionsort, n, &anzahl_befehle);
            }

            //speichere die Laufzeit sowie die Anzahl benötigter Befehle
            laufzeit_array[i][j] = end_timer();
            befehle_array[i][j] = anzahl_befehle;
        }

        //teste ob die Ausgabe beider Algorithmen gleich ist
        if(!check_equality_of_arrays(array_countsort, array_insertionsort, n))
        {
            printf("Die Arrays sind nicht gleich. Eines muss (falsch) sortiert worden sein!\n");
            rc = -1;
        }

        //gib den Speicherplatz wieder frei
        free(array_countsort);
        free(array_insertionsort);
    }

    //Ausgabe der Anzahl ausgeführter Befehle sowie der gemessenen Laufzeiten (in Millisekunden)
    printf("Parameter MAX_VALUE hat den Wert %d\n", MAX_VALUE);
    printf("\t %32s           %32s \n", "Countsort","Insertionsort");
    printf("%8s \t %16s %16s \t %16s %16s \n", "n","Befehle", "Laufzeit","Befehle","Laufzeit");

    for(int j = 0; j < LEN_WERTE; ++j)
    {
        printf("%8d \t ",WERTE[j]);
        for(int i = 0; i < LEN_ALGORITHMEN; ++i)
        {
            printf("%16ld %16.4f \t ",  befehle_array[i][j], laufzeit_array[i][j]);
        }
        printf("\n");
    }

    return rc;
}
