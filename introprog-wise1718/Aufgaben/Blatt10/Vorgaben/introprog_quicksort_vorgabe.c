/* === INTROPROG ABGABE ===
 * Blatt 10, Aufgabe 1
 * Tutorium: t28
 * Gruppe: g10
 * Gruppenmitglieder:
 *  - Pierre Louis
 *  - u
 * ========================
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "quicksort.h"

/*****************************************************
 * Die benoetigten structs findet Ihr in quicksort.h *
 *****************************************************/

void init_list(list* mylist)
{
// HIER Liste initialisieren
//initialisieren von newMylist
mylist->first=NULL;
mylist->last=mylist->first;
}



// Diese Funktion fügt Listenelemente an die Liste an
void insert_list(list_element* le, list* mylist)
{
    //wir haben shon ein pointer auf unsere neue list_element
    //Deswegen durfen wir kein neuer Speicher allozieren
    ///list_element* newElement = (list_element*)malloc(sizeof(list_element));
    ///newElement=le;

    //initialse the pointer at the beginning in the list
    if(mylist->last==NULL){  mylist->last=le;}

    le->next=mylist->first;
    mylist->first=le;

}

// Speicher für Listenelemente wieder freigeben
void free_list(list* mylist)
{
    while(mylist->first!=NULL){

      //free the elements of the list
      list_element* tmp= mylist->first->next;
      free(mylist->first);
      mylist->first=tmp;
    }

    //free the list
    //free(mylist);
}


// Namen, Zahlen Paare in Liste einlesen
void read_data(char* filename, list* mylist)
{
		// HIER Code einfügen:
        // * Speicher allozieren
        // * Daten in list_element einlesen
        // * insert_front benutzen um list_element in Liste einzufügen




  FILE *fpin = fopen(filename,"r");


  while(!feof(fpin)){
    char password[100];
    int count;

    fscanf(fpin,"%s %d", password,&count);//to read directly %s for string
//fscanf sind immer adressen
    //speicher allozieren
    list_element* newElement = (list_element*)malloc(sizeof(list_element));

    //newElement initialisieren
    sprintf(newElement->password,"%s",password);
    newElement->count= count;

    //in die Liste einfugen
    insert_list(newElement,mylist);


/*
    char buf[200];
    char *h = fgets(buf,200,fpin);
    if(h==0){
      printf("error in fgets");
      exit(1);
    }
    int ret = sscanf(buf, "%s %d\n",)
*/
  }

  //close the file
  fclose(fpin);
}

// Liste teilen. Teillisten werden in left und right zurück gegeben
list_element* partition( list* input, list* left, list* right )
{
  //picking the pivot element
  list_element* pivot = input->first;


  list_element* tmp=input->first->next;
  while(tmp!=NULL&&pivot!=NULL){
    if(tmp->count<pivot->count) insert_list(tmp,left);
    else insert_list(tmp,right);
    tmp=tmp->next;
  }

return pivot;
}

// Hauptfunktion des quicksort Algorithmus
void qsort_list(list* mylist)
{
    if(mylist->first!=mylist->last){//otherwise the list is sorted

      //initialse the two parts of the divided list
      //initialse pointers
      list* left= (list*)malloc(sizeof(list));
      init_list(left);
      list* right= (list*)malloc(sizeof(list));
      init_list(right);

      //initialse the pivot element
      list_element* pivot=partition(mylist,left,right);

      //recursiv call
      qsort_list(left);
      qsort_list(right);

      //kind of merging the pieces:
        //initialse the biginning and the end of the glued list
        //gluing the pivot at the wright place

      //first glue the pivot to the left list
      if(left->first==NULL) mylist->first=pivot;
      else{
        mylist->first=left->first;
        left->last->next = pivot;
      }

      //second glue the pivot to the right list
      if(right->first==NULL){
        pivot->next=NULL;
        mylist->last=pivot;
      }
      else{
        pivot->next=right->first;
        mylist->last=right->last;
      }
    }
}

// Liste ausgeben
void print_list(list* mylist)
{
  int indice=0;// the indice in the list
  list_element* tmp=mylist->first;

    while(tmp!=NULL){
      printf("L[%d]= %s %d\n",indice,tmp->password,tmp->count);
      indice++;
      tmp=tmp->next;
    }
}
