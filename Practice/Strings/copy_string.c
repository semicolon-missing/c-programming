//A program to copy one string to another

#include <stdio.h>

int main(){
	char str1[100];
	char str2[100];
	int i = 0;

	printf("Enter a string: ");
	fgets(str1, sizeof str1, stdin);

	while (str1[i] != '\0') {
		str2[i] = str1[i];
		i++;
	}

	printf("The copied string is %s\n", str2);

	return 0;

}
