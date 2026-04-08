#include <stdio.h>

void merge(int arr[], int start, int end, int mid){
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int arr1[n1], arr2[n2];

    for (i = 0; i < n1; i++){
        arr1[i] = arr[start + i];
    }

    for (j = 0; j < n2; j++){
        arr2[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2){
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int start, int end){
    if (start < end)
    {
        int mid = (start + end - 1) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);

        merge(arr, start, end, mid);
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

    mergesort(arr, 0, size - 1);
    printf("Sorted array: {");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");


    return 0;
}