#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **arr, int rows, int cols){
	printf("\nMatrix Contents:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", arr[i][j]);

		}
	printf("\n");
	}
}

int **make_2D_array(int rows, int cols){
    int **arr = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

void readMatrix(int **arr, int rows, int cols) {
	printf("Enter %d elements (%d per row): \n", rows*cols, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void addMatrix(int **arr1, int **arr2, int **arr3, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            arr3[i][j] = arr2[i][j] + arr1[i][j];
        }
    }
}


int main() {
    int rows, cols;
    printf("Enter the number of rows & Columns: \n");
    scanf("%d %d", &rows, &cols);

    int **a = make_2D_array(rows, cols);
    int **b = make_2D_array(rows, cols);
    int **c = make_2D_array(rows, cols);

    readMatrix(a, rows, cols);
    readMatrix(b, rows, cols);

    addMatrix(a, b, c, rows, cols);
    printMatrix(c, rows, cols);


    return 0;
}