#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;

    for (int i=0; i<len; i++) {
        printf("Checke %d = ", array[i]);
        if (array[i] % 2 > 0) {
            printf("Ungerade\n");
        } else {
            printf("Gerade\n");
        }
    }
}
