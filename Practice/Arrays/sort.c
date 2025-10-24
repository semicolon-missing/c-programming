#include <stdio.h>

int main(){
	int arr[] = {25, 89, 56, 32, 54, 108};

	int temp, i, j;

	for (i = 0; i < 6; i++) {
		for (j = 1; j < i; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < 6; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}
