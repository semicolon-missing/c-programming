// A program to compare two different strings

#include <stdio.h>

int test(char str1[], char str2[]){
	int flag = 0;
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] == str2[i]) {
			i++;
		} else if ((str1[i] == '\0' && str2[i] != '\0') || (str1[i] != '\0' && str2[i] == '\0') || (str1[i] != str2[i])) {
			flag = 1;
			break;
		}
	}

	return flag;
}


int main(){
	char str1[100];
	char str2[100];
	int flag = 0; 

	printf("Input the first string: ");
	fgets(str1, sizeof str1, stdin);

	printf("Input the second string: ");
	fgets(str2, sizeof str2, stdin);

	printf("\nString 1 is: %s\n", str1);
	printf("\nString 2 is: %s\n", str2);

	flag = test(str1, str2);

	if (flag == 0) {	
		printf("\nStrings are equal.\n");
	}
	else
		printf("\nStrings are not equal.\n");
	
	return 0;



}
