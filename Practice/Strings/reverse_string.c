//A program to reverse string

#include <stdio.h>
#include <string.h>


int main(){
	char str[100];
	
	//Input a string
	fgets(str, sizeof str, stdin);
	
	int l = strlen(str);
	
	printf("The string in reverse order is: ");
	for (int i = l - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");

	return 0;

}
