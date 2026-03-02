#include <stdio.h>
#include <stdlib.h>

int **make_2D_array(int rows, int cols){
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

void printMatrix(int **arr, int rows, int cols){
	printf("\nMatrix Contents:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", arr[i][j]);

		}
	printf("\n");
	}
}

int main() {
    int **arr = make_2D_array(5, 4);

    // Initialize with some values
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i + j;
        }
    }

    printMatrix(arr, 5, 4);

    // Free allocated memory
    for (int i = 0; i < 5; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}