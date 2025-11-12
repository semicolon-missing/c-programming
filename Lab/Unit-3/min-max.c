// 

#include <stdio.h>

void minmax_normalization(float arr[], int size){
	float norm_arr[size];
	float max = arr[0];
	float min = arr[0];

	for (int i = 1; i < size; i++){
		if (arr[i] < min){
			min = arr[i];
		}

		if (arr[i] > max){
			max = arr[i];
		}
	}

	if (max == min) {
		printf("All elements are equal.\n");
		return;
	}
	
	for (int i = 0; i < size; i++){
		norm_arr[i] = ((arr[i] - min) / (max - min));
	}

	for (int i = 0; i < size; i++){
		printf("%.2f ", norm_arr[i]);
	}

	printf("\n");
}

int main(){
	float arr[] = {50.0, 20.0, 30.0, 80.0, 90.0};
	int size = 5;
	minmax_normalization(arr, size);

	return 0;
}
