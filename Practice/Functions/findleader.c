#include <stdio.h>

void findLeaders(int arr[], int n) {
    printf("Leaders:\n");
    for (int i = 0; i < n; i++) {
        int isLeader = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isLeader = 0;
                break;
            }
        }
        if (isLeader) {
            printf("Value: %d, Index: %d\n", arr[i], i);
        }
    }
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    findLeaders(arr, n);
    return 0;
}