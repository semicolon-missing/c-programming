#include <stdio.h>

void insertion_sort(int arr[], int size){
    int i, j, key;

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;   
        }
        arr[j + 1] = key;
    }
    
}
void printArray(int arr[], int size)
{
    printf("{");
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
    insertion_sort(arr, size);
    printArray(arr, size);
    
    return 0;
}