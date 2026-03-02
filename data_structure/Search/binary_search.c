#include <stdio.h>
#include <stdlib.h>

int n;

void sort_array(int *arr, int size) {
    int temp;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[i]) {
                // Swap elements if they are in the wrong order
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binary_search(const int *arr, int target, int low, int high) {
    while(low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int target;
    
    printf("Input the size of array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Input the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    sort_array(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to be found: ");
    scanf("%d", &target);
    
    int result = binary_search(arr, target, 0, n - 1);
    
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d in the sorted array\n", result);
    }
    
    free(arr);
    return 0;
}