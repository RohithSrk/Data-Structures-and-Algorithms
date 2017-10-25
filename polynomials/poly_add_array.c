#include <stdio.h>
#include <stdlib.h>

int poly_add(int *a, int n1, int *b, int n2, int *c)
{
   int i = 0, j = 0, k = 0;

    while (i < n1 * 2 && j < n2 * 2)
    {
        if (a[i + 1] == b[j + 1]) {
            c[k] = a[i] + b[j];
            c[k + 1] = a[i + 1];
            k += 2;
            i += 2;
            j += 2;
        }
        else if (a[i + 1] > b[j + 1]) {
            c[k] = a[i];
            c[k + 1] = a[i + 1];
            k += 2;
            i += 2;
        } else {
            c[k] = b[j];
            c[k + 1] = b[j + 1];
            k += 2;
            j += 2;
        }
    }

    while (i < n1 * 2)
    {
        c[k] = a[i];
        c[k + 1] = a[i + 1];
        k += 2;
        i += 2;
    }

    while (j < n2 * 2)
    {
        c[k] = b[j];
        c[k + 1] = b[j + 1];
        k += 2;
        j += 2;
    }

   return k/2;
}

void poly_read(int *e, int n) {
    int i;
    for (i = 0; i < n * 2; i = i + 2)
        scanf("%d%d", &e[i], &e[i + 1]);
}

void display(int *e, int n) {
    int i;
    for (i = 0; i < n * 2; i = i + 2)
        printf("%dx%d  ", e[i], e[i + 1]);

    printf("\n");
}

void main() {
    int n1, n2, n3;
    int *a, *b, *c;

    printf("Enter the no.of terms in first expression: ");
    scanf("%d", &n1);

    printf("Enter the no.of terms in second expression: ");
    scanf("%d", &n2);

    a = (int *) malloc(2 * n1 * sizeof(int));
    b = (int *) malloc(2 * n2 * sizeof(int));
    c = (int *) malloc(2 * (n1 + n2) * sizeof(int));

    printf("Enter the first expression terms:");
    poly_read(a, n1);

    printf("first expression in memory: ");
    display(a, n1);

    printf("Enter the second expression terms: ");
    poly_read(b, n2);

    printf("second expression in memory: ");
    display(b, n2);

    n3 = poly_add(a, n1, b, n2, c);

    printf("Resultant expression: ");
    display(c, n3);
}

/*
Sample Run:
-----------
Enter the no. of terms in first expression:3
Enter the no. of terms in second expression:4
Enter the first expression terms:6 3 4 2 2 1
First expression in memory: 6x^3  4x^2  2x^1
Enter the second expression terms:5 4 4 3 2 2 1 1
Second expression in memory: 5x^4  4x^3  2x^2  1x^1
Resultant expression: 5x^4  10x^3  6x^2  3x^1
 */
