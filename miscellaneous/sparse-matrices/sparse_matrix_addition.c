/*
 * Aim:     A C Program to perform addition on two sparse matrices using structures.
 * Author:  Rohith
 * Date:    31-08-2017
 */

#include<stdio.h>

typedef struct term {
    int r;
    int c;
    int v;
} term;

int add_sparse_matrix(term a[], term b[], int na, int nb, term sc[]) {
    int k1, k2, k3;
    k1 = k2 = k3 = 0;

    while (k1 < na && k2 < nb) {
        if (a[k1].r == b[k2].r) {
            if (a[k1].c == b[k2].c) {
                sc[k3].r = a[k1].r;
                sc[k3].c = a[k1].c;
                sc[k3].v = a[k1].v + b[k2].v;

                k3++;
                k2++;
                k1++;
            } else if (a[k1].c < b[k2].c) {
                sc[k3].r = a[k1].r;
                sc[k3].c = a[k1].c;
                sc[k3].v = a[k1].v;

                k3++;
                k1++;
            } else if (b[k2].c < a[k1].c) {
                sc[k3].r = b[k2].r;
                sc[k3].c = b[k2].c;
                sc[k3].v = b[k2].v;

                k3++;
                k2++;
            }
        } else if (a[k1].r < b[k2].r) {
            sc[k3].r = a[k1].r;
            sc[k3].c = a[k1].c;
            sc[k3].v = a[k1].v;

            k1++;
            k3++;
        } else if (b[k2].r < a[k1].r) {
            sc[k3].r = b[k2].r;
            sc[k3].c = b[k2].c;
            sc[k3].v = b[k2].v;

            k3++;
            k2++;
        }
    }

    while (k1 < na) {
        sc[k3].r = a[k1].r;
        sc[k3].c = a[k1].c;
        sc[k3].v = a[k1].v;

        k3++;
        k1++;
    }

    while (k2 < nb) {
        sc[k3].r = b[k2].r;
        sc[k3].c = b[k2].c;
        sc[k3].v = b[k2].v;

        k3++;
        k2++;
    }

    printf("%d %d %d\n", k1, k2, k3);
    return k3;
}

void print_sparse(term arr[], int n) {
    int i;

    printf("\nr\tc\tv\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", arr[i].r, arr[i].c, arr[i].v);
    }
}

void main() {
    int na;
    int nb;
    int i;
    int resultSize;

    printf("Enter size of sparse matrix A: ");
    scanf("%d", &na);

    printf("Enter size of sparse matrix B: ");
    scanf("%d", &nb);

    term sa[na];
    term sb[nb];
    term sc[na + nb];

    printf("Enter r, c, v values of A:\n");
    for (i = 0; i < na; i++) {
        scanf("%d", &sa[i].r);
        scanf("%d", &sa[i].c);
        scanf("%d", &sa[i].v);
    }

    printf("Enter r, c, v values of B:\n");
    for (i = 0; i < nb; i++) {
        scanf("%d%d%d", &sb[i].r, &sb[i].c, &sb[i].v);
    }

    resultSize = add_sparse_matrix(sa, sb, na, nb, sc);

    printf("Result:");
    print_sparse(sc, resultSize);
}

/*
Sample Run:
-----------
Enter size of sparse matrix A:4
Enter size of sparse matrix B:4
Enter r, c, v values of A:
0 1 4
1 2 5
1 3 7
2 2 9
Enter r, c, v values of B:
0 2 6
1 2 7
2 1 6
2 3 9
4 4 7
Result:
r       c       v
0       1       4
0       2       6
1       2       12
1       3       7
2       1       6
2       2       9
2       3       9
 */