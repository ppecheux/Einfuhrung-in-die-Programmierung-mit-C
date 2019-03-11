#include <stdio.h>
#include <stdlib.h>

void print_array(int tab[], int tenght) {
  printf("Array: ");
    for(int i = 0; i<tenght; i++){
      printf("%d, ",tab[i]);
    }
}

int min (int tab[], int tenght){
  int minimum = tab[0];
  for(int i=1;i<tenght;i++){
    if (minimum>tab[i]){
      minimum = tab[i];
    }
  }
  return minimum;
}

int max (int tab[], int tenght){
  int maximum = tab[0];
  for(int i=0;i<tenght;i++){
    if (maximum<tab[i]){
      maximum = tab[i];
    }
  }
  return maximum;
}

int sum(int tab[], int tenght,int *s){
  *s=0;
  for(int i=0; i<tenght; i++){
    *s += tab[i];
  }
}

int main() {
    int array[] = {9, 4, 7, 8, 10, 5, 1, 6, 3, 2};
    int len = 10;
    int s = 0;
    sum (array,len,&s);
    print_array(array,len);
    printf("\nMinimum: %d\nMaximum: %d\nSumme: %d",min(array,len),max(array,len),s);
}
