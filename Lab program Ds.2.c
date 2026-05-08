#include<stdio.h>

int main() {
    int matrix[10][10], triplet[50][3], transpose[50][3];
    int i, j, m, n, k = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Convert to triplet form
    triplet[0][0] = m;
    triplet[0][1] = n;
    triplet[0][2] = 0;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
                triplet[0][2]++;
            }
        }
    }

    printf("\nTriplet Representation:\n");
    for(i = 0; i < k; i++) {
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }

    // Transpose
    transpose[0][0] = triplet[0][1];
    transpose[0][1] = triplet[0][0];
    transpose[0][2] = triplet[0][2];

    k = 1;

    for(i = 0; i < triplet[0][1]; i++) {
        for(j = 1; j <= triplet[0][2]; j++) {
            if(triplet[j][1] == i) {
                transpose[k][0] = triplet[j][1];
                transpose[k][1] = triplet[j][0];
                transpose[k][2] = triplet[j][2];
                k++;
            }
        }
    }

    printf("\nTranspose Triplet:\n");
    for(i = 0; i < k; i++) {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}
OUTPUT
Enter rows and columns: 1 4 7 8 5 2 3 6 9
Enter matrix elements:

Triplet Representation:
1 4 4
0 0 7
0 1 8
0 2 5
0 3 2

Transpose Triplet:
4 1 4
0 0 7
1 0 8
2 0 5
3 0 2
