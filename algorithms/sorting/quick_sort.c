#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int start, int end) {
    int pivot, pindex, i, temp;

    pivot = a[end];
    pindex = start;

    for (i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            temp = a[pindex];
            a[pindex] = a[i];
            a[i] = temp;

            ++pindex;
        }
    }

    temp = a[pindex];
    a[pindex] = a[end];
    a[end] = temp;

    return pindex;
}

void quick_sort(int *a, int start, int end) {
    int pindex;
    if (start < end) {
        pindex = partition(a, start, end);
        quick_sort(a, start, pindex - 1);
        quick_sort(a, pindex + 1, end);
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

    quick_sort(a, 0, n-1);

    printf("After Sorting: ");

    for(i = 0;i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
