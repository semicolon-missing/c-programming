#include <stdio.h>

// Recursive function to print array
void printArrayRecursive(int arr[], int size, int index) {
    // Base case: if index reaches the size, stop
    if (index == size) {
        return;
    }

    printf("%d ", arr[index]);

    // Recursive call for the next index
    printArrayRecursive(arr, size, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    printArrayRecursive(arr, n, 0);

    return 0;
}