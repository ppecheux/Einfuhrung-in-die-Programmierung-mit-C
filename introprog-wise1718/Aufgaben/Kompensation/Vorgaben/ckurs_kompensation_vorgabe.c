/* ==== KOMPENSATION ABGABE ====
 * Kompensationsaufgabe
 * Abgabe von: Erika Mustermann
 * =============================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_MATCH 200 // maximale Anzahl auszugebender Matches
#define MAX_STRING 255 // Maximale Wortlänge

/*** Datenstrukturen ***/
// QElement wird von Queue benutzt
struct QElement {
    // HIER Code einfügen
    // * Datenstruktur implementieren
};

typedef struct QElement QElement;

struct Queue {
    // HIER Code einfügen
    // * Datenstruktur implementieren
};

typedef struct Queue Queue;

// Queue initialisieren
Queue* init_queue() {
    // HIER Code einfügen
}

// Speicher der Qeue freigeben
void queue_freigeben(Queue *queue) {
    // HIER Code einfügen
};

// Füge string als QElement am Ende der Queue an
void enqueue(Queue *queue, char* string){
    // HIER Code einfügen
}

// Lösche das erste QElement der Queue
void dequeue (Queue *queue) {
    // HIER Code einfügen
}

// Debug Ausgabe für Queue
void queue_ausgeben(Queue *queue) {
    // HIER Code einfügen
}

// Vergleiche Inhalte zweier Queues bis zur Länge
int match(Queue *suchphrase, Queue *queue) {
    // HIER Code einfügen
}

int main(int argc, char** argv) {
    // Parameter einlesen
    if (argc < 3)
    {
        printf("Nutzung: %s <Dateiname> <Wort1> <Wort2> ...\n", argv[0]);
        return 1;
    }

    // HIER Code einfügen
    // * Initialisiere Queues
    // * Fülle die Queue der Suchphrase
    //   Tipp: Die Elemente findest du bei argv[2] bis argv[argc]
    // * Überpüfe mit queue_ausgeben ob du es korrekt eingelesen hast.

    // HIER Code einfügen
    // * Wörter aus Datei mit enqueue in die Queue befördern bis Queue voll ist.
    // * Von da an mit enqueue und dequeue Wörter in die Queue lesen und Queues
    //   vergleichen
    // * Gebe die Positionen der gefundenen Phrase im Text an, in dem du die Wörter des
    //   Text von 1 an hochzählst. Die Position der Phrase ist identisch mit der Position
    //   des ersten Wortes der Phrase.

    // HIER Speicher der Queues freigeben
    // * Überprüfe mit valgrind ob alles freigeben wird.
}
