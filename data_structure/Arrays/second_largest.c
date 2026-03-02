/*A program in C to find the second largest element in an array.*/


#include <stdio.h>

//Function to print array
void printArray(int arr[], int size) {
	printf("The elements of the array are: {");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("}\n");
}

//Function to sort an array
void sortArray(int arr[],int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main(){
	int arr[20] = {25, 45, 98, 15, 125, 76};
	
	
	printArray(arr, 6);

	sortArray(arr, 6);

	printf("The second largest element of the array is: %d\n", arr[1]);


	return 0;

	
}
