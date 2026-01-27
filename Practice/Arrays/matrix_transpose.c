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

void transpose(int matrix[ROWS][COLS],int result[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            result[i][j] = matrix[j][i];
        }
    }
}



int main() {
    int matrix[ROWS][COLS];
    int result[ROWS][COLS];
    
    printf("Enter a matrix: \n");
    readMatrix(matrix, ROWS);
    printMatrix(matrix, ROWS);

    transpose(matrix, result);

    printf("The transpose of the given matrix is: \n");
    printMatrix(result, ROWS);
    
    return 0;
}