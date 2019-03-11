#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Größen von Variablentypen\n");
    printf("int = %lu Bytes\n", sizeof(int));
    printf("long int = %lu Bytes\n", sizeof(long int));
    printf("long long int = %lu Bytes\n", sizeof(long long int));
    printf("float = %lu Bytes\n", sizeof(float));
    printf("char = %lu Bytes\n", sizeof(int));

    int zahl = 3;
    printf("int zahl = %lu Bytes\n", sizeof(zahl));

    int array[] = {1, 2, 3, 4, 5};
    printf("int array = %lu Bytes\n", sizeof(array));

    int array2[20];
    printf("int array2 = %lu Bytes\n", sizeof(array2));

    // aber klappt nur für statisch reservierten Speicher
    // int *array3 = (int*) malloc(sizeof(int) * 10);
    // printf("int array3 = %lu Bytes\n", sizeof(array3));
}
