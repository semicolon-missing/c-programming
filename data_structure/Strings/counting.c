//A program to count the total number of alphabets, digits and special characters in a string.

#include <stdio.h>
#include <string.h>

void counter(char str[]){
	int alphabets = 0;
	int digits = 0;
	int spch = 0;
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			alphabets++;	
		} else if (str[i] >= '0' && str[i] <= '9') {
			digits++;
		} else {
			spch++;
		}
		i++;
	}
	
	printf("Number of alphabets in the string is %d\n", alphabets);
	printf("Number of digits in the string is %d\n", digits);
	printf("Number of special characters in the string is %d\n",spch);
}
int main(){
	
	char str[100];
	
	printf("Enter a string: ");
	fgets(str, sizeof str, stdin);

	str[strcspn(str, "\n")] = 0;

	counter(str);
	

	return 0;
}
