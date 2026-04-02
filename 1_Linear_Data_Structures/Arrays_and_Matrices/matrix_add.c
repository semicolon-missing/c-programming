//A program to add two matrices

#include <stdio.h>
#define ROWS 3
#define COLS 3


void readMatrix(int matrix[][COLS], int rows) {
	printf("Enter %d elements (%d per row): \n", rows*COLS, COLS);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

void printMatrix(const int matrix[][COLS], int rows){
	printf("\nMatrix Contents:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d\t", matrix[i][j]);

		}
	printf("\n");
	}
}


void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++){
             result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}


int main(){
	int matrix1[ROWS][COLS];
	int matrix2[ROWS][COLS];
	int result[ROWS][COLS];


	printf("Enter first matrix: ");
	readMatrix(matrix1, ROWS);

	printMatrix(matrix1, ROWS);

	printf("Enter second matrix: ");
	readMatrix(matrix2, ROWS);

	printMatrix(matrix2, ROWS);

	addMatrix(matrix1, matrix2, result);

	// FIX: A call to 'printMatrix' was added to display the 'result' matrix. 
	// This allows verification of the matrix addition.
	printf("\nResultant matrix after addition:\n");
	printMatrix(result, ROWS);


}
