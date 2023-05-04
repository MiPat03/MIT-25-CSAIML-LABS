#include <stdio.h>

void multiply(int mat1[][100], int mat2[][100], int res[][100], int row1, int col1, int row2, int col2, int* ops) {
    int i, j, k;
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            res[i][j] = 0;
            for (k = 0; k < col1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
                (*ops)++; 
            }
        }
    }
}

void display(int mat[][100], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[100][100], mat2[100][100], res[100][100];
    int row1, col1, row2, col2;
    int i, j, ops = 0;
    
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &row1, &col1);
    
    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &row2, &col2);
    
    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    if (col1 != row2) {
        printf("Error: Matrix multiplication not possible.\n");
        return 0;
    }
    
    multiply(mat1, mat2, res, row1, col1, row2, col2, &ops);
    
    printf("Resultant matrix:\n");
    display(res, row1, col2);
    
    printf("Number of operations: %d\n", ops);
    
    return 0;
}
