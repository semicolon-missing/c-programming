#include <stdio.h>

void reverse_array(int arr[], int start, int end){
	while(start < end){
		int temp = arr[end];
		arr[end] = arr[start];
		arr[start] = int temp;
		start++;
		end--;
	}
}

void rotateArray(int arr[], int n, int k){
	k = k % n;
	reverse_array(arr, 0, n - 1);	//Reverse Total
	reverse_array(arr, 0, k - 1);	//Reverse first k
	reverse_array(arr, k, n - 1);	//Reverse remaining

}

void maxConsecutiveOnes(int arr[], int n){
	int max-cnt = 0, curr_cnt = 0; 
	for(int i = 0; i < n; i++){
		if(arr[i] == 1){
			curr_cnt++;
			if (curr_cnt > max_cnt) max_cnt = curr_cnt;
		} else {
			curr_cnt = 0;
		}

	}
	return max_cnt;
}

int main() {
	
	return 0;
}

