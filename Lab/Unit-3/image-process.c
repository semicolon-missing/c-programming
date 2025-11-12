#include <stdio.h>
#define ROWS 3
#define COLS 3

void img_process(int pixel[][3], int brightness){
	printf("Output Image: \n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			pixel[i][j] += 20;
			printf("%d\t", pixel[i][j]);
		}
		printf("\n");
	}

}	
	
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
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d\t", matrix[i][j]);

		}
	printf("\n");
	}
}

int main(){
	int pixel[ROWS][COLS];
	int brightness;

	printf("Enter the brightness adjustment: ");
	scanf("%d", &brightness);

	printf("Enter first matrix: ");
	readMatrix(pixel, ROWS);
	
	printf("Input Image: \n");
	printMatrix(pixel, ROWS);

	img_process(pixel, brightness);
	
	return 0;
}
