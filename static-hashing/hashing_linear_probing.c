#include <stdio.h>

#define MAX 20

int tsize;

int hasht(int key) {
    int i;
    i = key % tsize;
    return i;
}

int rehashl(int key) {
    int i;
    i = (key + 1) % tsize;
    return i;
}

int main() {
    int key, arr[MAX], hash[MAX], i, n, k;
    printf("Enter the size of the hash table:  ");
    scanf("%d", &tsize);

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < tsize; i++)
        hash[i] = -1;

    printf("Enter Elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (k = 0; k < n; k++) {
        key = arr[k];
        i = hasht(key);
        while (hash[i] != -1) {
            i = rehashl(i);
        }
        hash[i] = key;
    }

    printf("\nThe elements in the array are: ");
    for (i = 0; i < tsize; i++)
        printf("\n  Element at position %d: %d", i, hash[i]);
    return 0;
}
