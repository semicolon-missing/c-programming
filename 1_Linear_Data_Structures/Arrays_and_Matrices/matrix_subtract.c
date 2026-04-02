// A program to one matrix from another

#include <stdio.h>

#define ROWS 3
#define COLS 3

void readMatrix(int matrix[][COLS], int rows) {
	printf("Enter %d elements (%d per row): \n", rows*COLS, COLS);
	for (int i = 0; i < rows; i++) {
		// FIX: Changed 'cols' to 'COLS'.
		for (int j = 0; j < COLS; j++) {
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	
	}

}

void printMatrix(const int matrix[][COLS], int rows){
        printf("\nMatrix Contents:\n");
        for (int i = 0; i < rows; i++) {
                // FIX: Changed 'cols' to 'COLS'.
                for (int j = 0; j < COLS; j++) {
                        printf("%d\t", matrix[i][j]);

                }
        printf("\n");
        }
}

void subtractMatrix(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]){
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			 result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}


int main(){
	int matrix1[ROWS][COLS];
	int matrix2[ROWS][COLS];
	int result[ROWS][COLS];

	readMatrix(matrix1, ROWS);
	printMatrix(matrix1,ROWS);

	readMatrix(matrix2, ROWS);
	printMatrix(matrix2, ROWS);

	subtractMatrix(matrix1, matrix2, result);

	printf("\nResult after subtraction is: \n");
	printMatrix(result, ROWS);

	return 0;
	
}
