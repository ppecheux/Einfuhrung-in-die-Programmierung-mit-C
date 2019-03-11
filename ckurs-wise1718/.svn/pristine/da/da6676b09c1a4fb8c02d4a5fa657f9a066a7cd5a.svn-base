#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 10;
    int type_size = sizeof(char);
    int *array;

    printf("Adresse %p\n", array);

    // statische Variante: array[size]
    array = malloc(size * type_size);
    printf("Adresse %p\n", array);

    free(array);
    printf("Adresse %p\n", array);
}
