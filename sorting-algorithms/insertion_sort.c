#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a, int n) {
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i;
        while (j > 0 && a[j - 1] > temp)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

int main() {
    int n, i, *a;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertion_sort(a, n);
    printf("After Sorting: ");

    for(i = 0;i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
