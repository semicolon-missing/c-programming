#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int start, int end){
    int pivot = arr[end];
    int index = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            index++;
            swap(&arr[index], &arr[j]);
        }
        
    }
    swap(&arr[index + 1], &arr[end]);
    return index + 1;
}

void quicksort(int *arr, int start, int end){
    if (start < end){
        int pi = partition(arr, start, end);
        quicksort(arr, start, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}

int main() {
    int arr[] = {12, 8, 3, 17, 9, 6};
    int size = sizeof(arr) / sizeof(int);
    
    printf("Unsorted array: {");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    quicksort(arr, 0, 5);
    printf("Sorted array: {");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");

    return 0;
}