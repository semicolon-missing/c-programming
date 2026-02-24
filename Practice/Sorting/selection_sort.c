#include <stdio.h>

void selection_sort(int arr[], int size){
    int i, j, min_index;
    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (int j = 0; j < size; j++) {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
                swap(&arr[min_index], &arr[i]);
            }
            
            
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int size)
{
    printf("The elements of the array are: {");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    int arr[] = {12, 89, 3, 45, 11, 76};
    int size = sizeof(arr) / sizeof(int);
    selection_sort(arr, size);
    printArray(arr, size);
    
    return 0;
}