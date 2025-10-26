//A program to read a 2D array of size 3*3 and print the matrix

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
int main(){
	int myMatrix[ROWS][COLS];
	
	readMatrix(myMatrix, ROWS);

	printMatrix(myMatrix, ROWS);

	return 0;
	
}
