/*
 * Aim:     A C Program to generate sparse matrix.
 * Author:  Rohith
 * Date:    31-08-2017
 */

#include <stdio.h>

void main()
{
    int mat[10][10];
    int m, n, i, j, count = 0;

    printf("Enter the order of the matrix (m n): ");
    scanf("%d%d", &m, &n);

    printf("Enter the matrix:\n");
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
            if(mat[i][j] != 0) count++;
        }
    }

    printf("Sparse Matrix:\n");
    printf("%d %d %d\n", m, n, count);
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if(mat[i][j] != 0)
                printf("%d %d %d\n", i, j, mat[i][j]);
        }
    }
}

/*
Sample Run:
-----------
Enter the order of the matrix (m n):4 4
Enter the matrix:
1 0 0 0
0 1 2 0
8 0 0 0
0 0 0 1
Sparse Matrix:
4 4 5
0 0 1
1 1 1
1 2 2
2 0 8
3 3 1
*/