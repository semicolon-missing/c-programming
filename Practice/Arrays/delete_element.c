//A program in C to delete an element at a desired position from an array.

#include <stdio.h>

int main(){
	int arr[20] = {16, 89, 20, 68, 45, 98};
	int position;
	int size = 6;

	// printing the array
	printf("The elements of the array is: {");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < (size - 1)) {
			printf(", ");
		}
	}
	printf("}\n");

	//reading the position of the number to be deleted
	printf("Enter the position of the number: ");
	scanf("%d", &position);

	//deleting the element
	for (int i = position; i < size; i++) {
		arr[i - 1] = arr[i];
	}
	
	size--;

	//printing the array
	printf("The elements of the array is: {");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < (size - 1)) {
			printf(", ");
		}
	}
	printf("}\n");

	return 0;
}
