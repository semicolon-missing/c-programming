//a program in C to find the second smallest element in an array. 

#include <stdio.h>

void sortArray(int arr[],int size) {
        for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                        // FIX: Sort in ascending order to easily find the second smallest element.
                        if (arr[j] > arr[j + 1]) {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}


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


// FIX: Removed the 'size' parameter as it was unused and misleading.
// The function now declares its own size variable.
int readArray(int arr[]) {
	int size;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size);

	printf("Enter the elements of the array: ");
	for (int i = 0; i < size; i++) {
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	return size;
}

int main(){
	
	int arr[20];
	int size;

	// FIX: Assign the returned size from readArray to the 'size' variable.
	// The 'size' variable in main was previously uninitialized.
	size = readArray(arr);
	printArray(arr, size);
	sortArray(arr, size);

	// FIX: The second smallest element is at index 1 in an ascendingly sorted array.
	// The array is now sorted in ascending order.
	printf("The second smallest element in the array is: %d\n", arr[1]);
		
	return 0;
}
