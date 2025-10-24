//a program in C to separate individual characters from a string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[100];
	int i = 0;

	printf("Input the string: ");

	fgets(str, sizeof str, stdin);
	str[strcspn(str, "\n")] = '\0';

	printf("The characters of the string are: ");

	while(str[i] != '\0') {
		printf("%c ", str[i]);
		i++;
	}

	printf("\n");
	
	return 0;
}
