#include <stdio.h>


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
            
        }
        if(flag == 0)
            break;
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

    bubble_sort(arr, size);
    printf("Sorted array: {");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");


    return 0;
}