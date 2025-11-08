//a program in C for the multiplication of two square matrices. 

#include <stdio.h>

#define ROWS 3
#define COLS 3

void readMatrix(int matrix[][COLS], int rows) {
        printf("Enter %d elements for a %d_by_%d matrix: \n", rows*COLS, rows, COLS);
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < COLS; j++) {
                        printf("element - [%d],[%d] : ", i, j);
                        scanf("%d", &matrix[i][j]);
                }
        }
}

void printMatrix(const int matrix[][COLS], int rows){
        printf("\nThe matrix is : \n");
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < COLS; j++) {
                        printf("%d\t", matrix[i][j]);
                }
        printf("\n");
        }
}

void matrixMultiply(int matrixA[][COLS], int matrixB[][COLS], int result[][COLS]){
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			result[i][j] = 0;
			for (int k = 0; k < COLS; k++) {
				result[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}

int main(){
	int matrix1[ROWS][COLS];
	int matrix2[ROWS][COLS];
	int result[ROWS][COLS];

	printf("Enter elements for the first matrix:\n");
	readMatrix(matrix1, ROWS);
	printMatrix(matrix1, ROWS);
	
	printf("\nEnter elements for the second matrix:\n");
	readMatrix(matrix2, ROWS);
	printMatrix(matrix2, ROWS);

	matrixMultiply(matrix1, matrix2, result);

	printf("\nResult of matrix multiplication:\n");
	printMatrix(result, ROWS);

	return 0;
}
