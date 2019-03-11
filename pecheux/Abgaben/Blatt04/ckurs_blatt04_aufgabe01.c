#include <stdio.h>
#include <stdlib.h>
#include "input.h" // Hier binden wir die Bibliothek ein

int fibonacci(int nummer){
  if(nummer==1||nummer==2){
    return 1;
  }
  else{
    return (fibonacci(nummer-2)+fibonacci(nummer-1));
  }
}

int main(){
    int n = lese_int(); // Hier rufen wir die Funktion lese_int auf.
    int f = fibonacci(n);
    printf("Fib(%d) = %d\n" , n, f); 

    return 0; //Beende das Programm ohne Fehlermeldung
}
