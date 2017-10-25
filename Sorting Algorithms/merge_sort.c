#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int *L, int leftcount, int *R, int rightcount) {
    int i = 0, j = 0,k = 0;

    while(i < leftcount && j < rightcount)
    {
        if(L[i] < R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while(i < leftcount) A[k++] = L[i++];
    while(j < rightcount) A[k++] = R[j++];
}

void merge_sort(int* A, int n) {
    int mid, i, *L, *R;

    if(n < 2) return;

    mid = n/2;

    L = (int *) malloc(mid * sizeof(int));
    R = (int *) malloc((n - mid) * sizeof(int));

    for(i = 0; i < mid; i++)
        L[i] = A[i];

    for(i = mid; i < n; i++)
        R[i-mid] = A[i];

    merge_sort(L,mid);
    merge_sort(R,n-mid);
    merge(A, L, mid, R, n-mid);
}

int main() {
    int n, i, *a;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(a, n);
    printf("After Sorting: ");

    for(i = 0;i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
