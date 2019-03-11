#include <stdio.h>
#include <stdlib.h>
#include "input2.h"

int main() {
    int* array = NULL;
    int n = lese_int();
    int laenge = n-1;
    //printf("laenge=%d",laenge);
    if (laenge>=1){
      array = malloc(laenge * sizeof(int));
      if(array == NULL){
        exit(0);
      }
    for(int i=0;i<laenge;i++){
      array[i]=1;
    }
    int i = 0;
    int m = 0;
    while(i<laenge){
      if (array[i]==1){
        m=i;
        while ((i+m*(i+2))<laenge){
          if (i!=0||m!=0){
          array[i+m*(i+2)]=0;}
          m++;
        //  printf("\ni=%d et m=%d",i,m);
        }
      }
    i++;
    }

   print_prim(array, laenge);
   free(array);
}
    return 0;
}
