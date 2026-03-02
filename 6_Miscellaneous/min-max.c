#include <stdio.h>

float min_array(float arr[], int size){
	float min = arr[0];
	for (int i = 0; i < size; i++){
		if (arr[i] < min){
		min = arr[i];
		}
	}
	return min;
}

// FIX: Changed parameter from 'float arr' to 'float arr[]' to correctly accept an array.
float max_array(float arr[], int size){
	float max = arr[0];
	for (int i = 0; i < size; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

void normalisation(float arr[], int size, float min, float max){
	float norm_array[size];

	if (min == max){
		printf("All elements are equal\n");
		return;
	}

	for (int i = 0; i < size; i++){
		norm_array[i] = ((arr[i] - min) / (max - min));
		printf("%.2f ", norm_array[i]);	
	}

	printf("\n");
}

int main() {
	float arr[] = {50.0, 20.0, 36.7, 75.8, 64.51}; // FIX: Added missing semicolon.
	int size = 5;
	float min, max;

	min = min_array(arr, size);
	max = max_array(arr, size);

	normalisation(arr, size, min, max); // FIX: Added missing semicolon.

	return 0;
}

