#include <stdio.h>

int main(){
	int arr[20] = {15, 20, 54, 64, 98, 105};
	int size = 6; //Initial size of array
	int num;

	//Printing the array
	printf("\nThe elements of the array are: {");
	for (int i = 0; i < size; i++){
		printf("%d", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("}");

	//Input the number to be inserted
	printf("\nEnter a number: ");
	scanf("%d", &num);

	//Finding the position for the number
	int position = 0;
	for (int i = 0; i < size; i++) {
		if (num <= arr[i]) {
			position = i;
			break;
		}
	}

	//Shifting the elements to create space 
	for (int i = size; i > position; i--) {
		arr[i] = arr[i - 1];
	}

	//Inserting the number
	arr[position] = num;

	//Increasing the size of the array
	size++;

	//Printing the array
	printf("\nThe new array is: {");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("}");
	printf("\n");

	return 0;

}
