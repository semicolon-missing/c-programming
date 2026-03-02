// A program to count the longest sequence of 1s in a 1d array

#include <stdio.h>

int main() {
	int arr[] = {1, 1, 0, 1, 1, 1, 0, 1};
	int count = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	int current_len = 0;
	int max_len = 0;

	for (int i = 0; i < size; i++){
		if (arr[i] == 1){
			current_len++;
			//Update max_len if current run is longer
			if (current_len > max_len) {
				max_len = current_len;
			}
		} else {
			// Reset counter when a 0 is ecountered
			current_len = 0;
		}
	}

	printf("The length of the largest consecutive sequence of 1s is %d\n", max_len);

	return 0;
}

