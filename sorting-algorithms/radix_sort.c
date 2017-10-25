#include <stdio.h>
#include <stdlib.h>

int max_num_length(int *arr, int n) {
    int max = 0, i, l = 0;

    for (i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    while (max > 0) {
        l++;
        max /= 10;
    }

    return l;
}

void radix_sort(int *arr, int n) {
    int buckets[10][n], bucket_count[10], maxl, p, i, divisor = 1, rem;
    int j, k, m;

    maxl = max_num_length(arr, n);

    for (p = 0; p < maxl; p++)
    {
        for (i = 0; i < 10; i++)
            bucket_count[i] = 0;

        for (i = 0; i < n; i++) {
            rem = (arr[i] / divisor) % 10;
            buckets[rem][bucket_count[rem]] = arr[i];
            bucket_count[rem]++;
        }
        divisor *= 10;

        m = 0;
        for (k = 0; k < 10; k++)
            for (j = 0; j < bucket_count[k]; j++)
                arr[m++] = buckets[k][j];

    }
}

int main() {
    int n, i, *a;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radix_sort(a, n);

    printf("Sorted Array:");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
