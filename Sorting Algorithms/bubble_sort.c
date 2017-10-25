#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n) {
    int i, j, temp;

    for (j = n - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (a[i + 1] < a[i])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
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

    bubble_sort(a, n);
    printf("After Sorting: ");

    for(i = 0;i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
