//A program to count words in a string

#include <stdio.h>
#include <string.h>

int countWords(char str[]){
	int count = 1;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			count++;
		}
		i++;
	}
	return count;
}
int main(){
	char str[100];

	printf("ENter a string: ");
	fgets(str, sizeof str, stdin);
	
	int count = countWords(str);

	printf("The number of words in the string is: %d\n", count);

	return 0;

}
