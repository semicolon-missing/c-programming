// A program to count number of vowels and consonants in a string

#include <stdio.h>
#include <ctype.h>

int main (){
	char str[100];
	int i = 0;
	int vowel_counter = 0;
	int consonant_counter = 0;

	printf("Enter a string: ");
	fgets(str, sizeof str, stdin);
				
	while (str[i] != '\0') {
		char ch = tolower(str[i]);
		if (isalpha(ch)) {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				vowel_counter++;
			}

			else {
				consonant_counter++;
			}
		}
		i++;

	}
	printf("Number of vowels in this string is %d.\n", vowel_counter);
	printf("Number of consonants in this string is %d.\n", consonant_counter);


	return 0;
}
