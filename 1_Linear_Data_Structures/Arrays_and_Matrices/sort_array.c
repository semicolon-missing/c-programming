#include <stdio.h>
int main(){

	int arr[100];
	int n, i, j, temp;

	printf("Sort elements of an array in ascending order:\n");
	printf("----------------------------------------------\n");
	printf("Input the size of array: ");
	scanf("%d", &n);

	//Input elements of array
	printf("Input the elements of the array:\n");
	for(i = 0; i < n; i++) {
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	//Sorting elements in ascending order using the Bubble Sort Algorithm
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(arr[j] < arr[i]) {

				//Swap elements if they are in the erong order
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	
	}
	
	//Print sorted array
	printf("\nElements of the array in ascending order: {\n");
	for(i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("}\n\n");

	return 0;


}
