#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *a, int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }

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

    selection_sort(a, n);
    printf("After Sorting: ");

    for(i = 0;i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
