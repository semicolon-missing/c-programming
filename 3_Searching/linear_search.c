#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int flag = 0;
    int data;
    int *arr = (int *)malloc(n * sizeof(int));


    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    printf("Enter an array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The array is:{\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to be found: ");
    scanf("%d", &data);

    for (int i = 0; i < n; i++) {
        if (arr[i] == data){
            flag = 1;
            printf("Element found at index %d", i);
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element not found.\n");
    }
    free(arr);
    return 0;
}