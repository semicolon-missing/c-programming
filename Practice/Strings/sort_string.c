//a C program to sort a string array in ascending order.

#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	int l;
	char ch;

	printf("\nSort a string in ascending order:\n");
	printf("------------------------------------\n");
	
	//Reading a string 
	printf("Enter a string: ");
	fgets(str, sizeof str, stdin);

	l = strlen(str);
	
	//Bubble sort algorithm to sort the string
	for (int i = 0; i < l; i++){
		for (int j = 0; j < l - i; j++){
			if (str[j] > str[j + 1]){
				ch = str[j];
				str[j] = str[j + 1];
				str[j + 1] = ch;
			}
		}
	}


	printf("Sorted string is: %s\n", str);

	return 0;

}
