// A Program to rotate the elements of a one dimensional array to the right by k positions.

#include <stdio.h> // Include standard input/output library for functions like printf and scanf

int main(){
	// Declare and initialize the original array
	int arr1[] = {0, 15, 87, 65, 21};
	int n; // Declare an integer to store the shift value (k positions)
	int size = 5; // Declare and initialize the size of the array
	int arr2[5]; // Declare a new array to store the rotated elements

	// Prompt the user to enter the shift value
	printf("Enter the value you want the array to be shifted by: ");
	// Read the shift value from the user and store it in 'n'
	scanf("%d", &n);
	
	// Loop through the original array to perform the rotation
	for(int i = 0; i < size; i++){
		// Calculate the new position for each element after rotation
		// (i + n) ensures shifting to the right by 'n' positions
		// % size handles wrapping around the end of the array to the beginning
		arr2[(i + n) % size] = arr1[i];
	}

	// Print the original array
	printf("Original array: ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr1[i]);
	}
	printf("\n"); // Print a newline character for formatting

	// Print the rotated array
	printf("Rotated array: ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr2[i]);
	}
	printf("\n"); // Print a newline character for formatting

	return 0; // Indicate successful execution of the program
}

