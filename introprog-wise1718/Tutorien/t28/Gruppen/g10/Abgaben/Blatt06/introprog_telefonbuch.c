/* === INTROPROG ABGABE ===
 * Blatt 6, Aufgabe 2
 * Tutorium: t28
 * Gruppe: g10
 * Gruppenmitglieder:
 *  - pecheux pierre-Louis
 *  - zweite gruppmitglieder
 * ========================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "introprog_telefonbuch.h"

// Fügt einen Knoten mit der Telefonnummer phone und dem Namen name in den
// Binären Suchbaum bst ein.  Für den Suchbaum soll die Eigenschaft gelten, dass
// alle linken Kinder einen Wert kleiner gleich (<=) und alle rechten Kinder
// einen Wert größer (>) haben.
void bst_insert_node(bstree* bst, unsigned long phone, char *name) {
  //initialisation of our newNode
  bst_node *newNode = malloc(sizeof (bst_node));//malloc of our newNode
  newNode->phone=phone;
  //counting the number of letters in the string;
  //int size= 0;
  newNode->name= malloc(sizeof(char)*(strlen(name)+1));
  strncpy(newNode->name,name,strlen(name));
  newNode->name[strlen(name)]='\0';
  //printf(",%c",name[MAX_STR-2]);
  newNode->right=NULL;
  newNode->left=NULL;

  //FRAGE was passiert wenn diese telephonnummer shon exiestiert?
  //FRAGE mussen wir die find node methode verwenden?

  //beginning of the insert program
  //hilfe von Vorlesung Baume, Folie 112
  bst_node *parent=NULL;//parent is like the y
  bst_node *x=bst->root;
  //printf("starte schleife\n");
  while (x!=NULL){

    parent=x;
    if (newNode->phone<x->phone)
      x=x->left;
    else if(newNode->phone>x->phone)
      x=x->right;
    else{//wenn beide nummer gleich sind
      printf("already exist");
      return;//x uberschreiben
      }
    }
    newNode->parent=parent;
    if (parent==NULL)
      bst->root=newNode;
    else{
      if(newNode->phone<parent->phone)
        parent->left=newNode;
      else
        parent->right=newNode;
    }
  }

// Diese Funktion liefert einen Zeiger auf einen Knoten im Baum
// mit dem Wert phone zurück, falls dieser existiert. Ansonsten wird
// NULL zurückgegeben.
bst_node* find_node(bstree* bst, unsigned long phone) {
  bst_node *tmp =bst->root;
  while(tmp!=NULL&&tmp->phone!=phone){
    if(phone<tmp->phone){
      tmp=tmp->left;
    }
    else{
      tmp=tmp->right;//searching in the tight subtree
    }
  }
  if(tmp==NULL){//if it doesnt exist
    return NULL;
  }
  else if(tmp->phone==phone){
    return tmp;
  }
  free(tmp->name);
  free(tmp);

  /*

  if(bst->root==NULL){//if it doesnt exist
    return NULL;
  }
  else if(bst->root->phone==phone){
    return bst->root;

  }
  if(phone<bst->root->phone){
    bst->root=bst->root->left;
    return find_node(bst,phone);
  }
  else{
    bst->root=bst->root->right;//searching in the tight subtree
    return find_node(bst,phone);
  }*/

}

// Gibt den Unterbaum von node in "in-order" Reihenfolge aus
void bst_in_order_walk_node(bst_node* node) {
  if(node!=NULL){
    bst_in_order_walk_node(node->left);
    print_node(node);
    bst_in_order_walk_node(node->right);
  }
}

// Gibt den gesamten Baum bst in "in-order" Reihenfolge aus. Die Ausgabe
// dieser Funktion muss aufsteigend soriert sein.
void bst_in_order_walk(bstree* bst) {
    if (bst != NULL) {
        bst_in_order_walk_node(bst->root);
    }
}

// Löscht den Teilbaum unterhalb des Knotens node rekursiv durch
// "post-order" Traversierung, d.h. zurerst wird der linke und dann
// der rechte Teilbaum gelöscht. Anschließend wird der übergebene Knoten
// gelöscht.
void bst_free_subtree(bst_node* node) {
  if (node==NULL)return;
  if (node->left!=NULL)bst_free_subtree(node->left);
  if (node->right!=NULL)bst_free_subtree(node->right);
  free(node->name);
  free(node);
/*
//(c)hat zwei Kinder
if((node->left!=NULL&&node->right!=NULL)){
  bst_free_subtree(node->left);
  bst_free_subtree(node->right);
  free(node);
  return;
}

  //(b.1) hat ein Kinder left
  if((node->left!=NULL&&node->right)){
    bst_free_subtree(node->left);
    free(node);
    return;

  }
  //(b.2) hat ein Kinder right
  if((node->left==NULL&&node->right!=NULL)){
    bst_free_subtree(node->right);
    free(node);
    return;
    }

  //(a) kein Kinder
  if(node->left==NULL&&node->right==NULL){
    free(node);
    return;
  }*/
}

// Löscht den gesamten Baum bst und gibt den entsprechenden Speicher frei.
void bst_free_tree(bstree* bst) {
    if(bst != NULL && bst->root != NULL) {
        bst_free_subtree(bst->root);
        bst->root = NULL;
    }
}
