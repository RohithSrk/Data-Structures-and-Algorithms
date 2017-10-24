/*
 * Aim:     A C Program to perform addition on two polynomials using arrays.
 * Author:  Rohith
 * Date:    02-09-2017
 */
#include <stdio.h>
#include <stdlib.h>

int poly_add(int **a, int n1, int **b, int n2, int **c) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i][1] == b[j][1]) {
            c[k][0] = a[i][0] + b[j++][0];
            c[k++][1] = a[i++][1];
        }
        else if (a[i][1] > b[j][1]) {
            c[k][0] = a[i][0];
            c[k++][1] = a[i++][1];
        } else {
            c[k][0] = b[j][0];
            c[k++][1] = b[j++][1];
        }
    }

    while (i < n1) {
        c[k][0] = a[i][0];
        c[k++][1] = a[i++][1];
    }

    while (j < n2) {
        c[k][0] = b[j][0];
        c[k++][1] = b[j++][1];
    }

    return k;
}

void poly_read(int **e, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d%d", &e[i][0], &e[i][1]);
    }
}

void display(int **e, int n) {
    int i;
    for (i = 0; i < n; i++) {
        //printf("%dx%d  ", e[i][0], e[i][1]);
        printf("%dx%d  ", *(*(e + i) + 0), *(*(e + i) + 1));
    }

    printf("\n");
}

void main() {
    int n1, n2, n3, i;
    int **a, **b, **c;

    printf("Enter the no.of terms in first expression: ");
    scanf("%d", &n1);

    printf("Enter the no.of terms in second expression: ");
    scanf("%d", &n2);

    a = (int **) malloc(n1 * sizeof(int));
    for (i = 0; i < n1; i++) {
        a[i] = (int *) malloc(2 * sizeof(int));
    }

    b = (int **) malloc(n2 * sizeof(int));
    for (i = 0; i < n2; i++) {
        b[i] = (int *) malloc(2 * sizeof(int));
    }

    c = (int **) malloc((n1 + n2) * sizeof(int));
    for (i = 0; i < (n1 + n2); i++) {
        c[i] = (int *) malloc(2 * sizeof(int));
    }

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