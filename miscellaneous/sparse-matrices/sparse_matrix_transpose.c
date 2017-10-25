/*
 * Aim:     A C Program to transpose a sparse matrix using structures.
 * Author:  Rohith
 * Date:    31-08-2017
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct smarray
{
    int r, c, v;
} *a, *b;

void main()
{
    int t;

    printf("Enter the number of non zero elements in sparse matrix: ");
    scanf("%d", &t);

    a = (struct smarray *) malloc((t+1) * sizeof(struct smarray));
    b = (struct smarray *) malloc((t+1) * sizeof(struct smarray));
    a[0].v = t;

    printf("Enter the number of rows of matrix: ");
    scanf("%d", &a[0].r);

    printf("Enter the number of columns of matrix: ");
    scanf("%d", &a[0].c);

    printf("Enter the non zero elements of sparse matrix: \n");
    read_spm(a, t);

    transpose_spm(a, b, t);

    printf("Sparse Matrix after transposing:\n");
    print_spm(b, t);
}

void read_spm(struct smarray *a, int t)
{
    int i;
    for(i = 1; i <= t; i++){
        scanf("%d %d %d", &a[i].r, &a[i].c, &a[i].v);
    }
}

void transpose_spm(struct smarray *a, struct smarray *b, int t){
    int l, m, k = 1;

    b[0].r = a[0].c; // No. of Matrix columns.
    b[0].c = a[0].r; // No. of Matrix rows.
    b[0].v = a[0].v; // No .of non zero elements.

    for(l = 0; l < a[0].c; l++)
    {
        for(m = 1; m <= a[0].v; m++){
            if(l==a[m].c)
            {
                b[k].r = a[m].c;
                b[k].c = a[m].r;
                b[k].v = a[m].v;
                k++;
            }
        }
    }
}

void print_spm(struct smarray *a, int t)
{
    int i;
    for(i = 0; i <= t; i++){
        printf("%d %d %d\n", a[i].r, a[i].c, a[i].v);
    }
}

/*
Sample Run:
-----------
Enter the number of non zero elements in sparse matrix: 4
Enter the number of rows of matrix: 3
Enter the number of columns of matrix: 4
Enter the non zero elements of sparse matrix:
1 0 5
1 2 3
2 1 1
2 3 2
Sparse Matrix after transposing:
4 3 4
0 1 5
1 2 1
2 1 3
3 2 2
 */