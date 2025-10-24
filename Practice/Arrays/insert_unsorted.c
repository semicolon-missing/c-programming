//A program in C to insert values in the array (unsorted list)

#include <stdio.h>


int main(){
	int arr[20] = {1, 89, 25, 19, 34, 9};
	int num, size = 6;
	int position;

	printf("The elements of the array are: {");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("}\n");

	//Reading the number to be inserted
	printf("Enter a number to inserted: ");
	scanf("%d", &num);

	//Reading the position of the number
	printf("Enter the position you want the number to be inserted at: ");
	scanf("%d", &position);

	for (int i = size; i > (position - 1); i--) {
		arr[i] = arr[i - 1];
	}

	arr[(position - 1)] = num;

	//Increasing the size of array
	size++;

	//Printing the new array
	printf("After inserting, the new array is: {");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);

		if (i < size - 1) {
			printf(", ");
		}
	}

	return 0;
}
