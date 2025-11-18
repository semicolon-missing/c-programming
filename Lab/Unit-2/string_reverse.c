#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "Hello World";
	int l = strlen(str);
	int start = 0;
	int end = l - 1;
	char temp;
	
	printf("Original String: %s\n", str);

	while (start < end){
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
	
	printf("Reversed String: %s\n", str);


	return 0;	

}

