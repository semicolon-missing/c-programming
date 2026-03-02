//A program in C to find the length of a string without using library functions. 


#include <stdio.h>

int strlength(char str[]) {
	int num = 0; //Error: The loop should start from 0
	while (str[num] != '\0') {
		num++;
	}

	return num;
}


int main(){
	char str[100];
	int num = 0;

	fgets(str, sizeof str, stdin);

	num = strlength(str); //Error: The value from the function was not being stored

	printf("The lenght of the string entered is: %d\n", (num - 1));

	return 0;

}
