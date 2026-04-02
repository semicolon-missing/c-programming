// A Program to rotate the elements of a one dimensional array to the right by k positions.

#include <stdio.h> /

int main(){
	// Declare and initialize the original array
	int arr1[] = {0, 15, 87, 65, 21};
	int n; 
	int size = 5; 
	int arr2[5]; 

	
	printf("Enter the value you want the array to be shifted by: ");
	scanf("%d", &n);
	
	// Loop through the original array to perform the rotation
	for(int i = 0; i < size; i++){
		
		arr2[(i + n) % size] = arr1[i];
	}

	// Print the original array
	printf("Original array: ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr1[i]);
	}
	printf("\n"); 

	// Print the rotated array
	printf("Rotated array: ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr2[i]);
	}
	printf("\n");
	
	
	return 0; 
}

