#include <stdio.h>

// Function prototype
void printArray(int arr[], int index, int len);

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array elements: ");
    printArray(numbers, 0, size);
    printf("\n");

    return 0;
}

// Recursive function to print array elements
void printArray(int arr[], int index, int len) {
    // Base case: Stop recursion when the index reaches the array length
    if (index >= len) {
        return;
    } 
    // Recursive call to process the next element
    printArray(arr, index + 1, len);

    printf("%d ", arr[index]);
}