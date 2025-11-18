#include <stdio.h>
#include <string.h>

	
int main(){
	char str[100];
	int len, n;
	int maxCount = 0;
	int maxIndex = -1;

	//Input a string
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	//Remove new line character
	str[strcspn(str, "\n")] = 0;
	n = strlen(str);

	//Input the length of substring to look for
	printf("Enter the length of substring to find: ");
	scanf("%d", &len);

	if(len > n || len <= 0){
		printf("Invalid substring length.\n");
		return 1;
	}

	//Compare every substring with every other substring
	for (int i = 0; i <= n - len; i++){
		int currentCount = 1;
		for (int j = i + 1; j <= n-len; j++){
			if (strncmp(&str[i], &str[j], len) == 0){
				currentCount++;
			}
		}
		if (currentCount > maxCount){
			maxCount = currentCount;
			maxIndex = i;
		}

	}

	if (maxIndex != -1){
		printf("Most occurring substring of length %d is: ", len);

		for (int k = 0; k < len; k++){
			printf("%c", str[maxIndex + k]);
		}

		printf("\nFrequency: %d times\n", maxCount);
	} else {
		printf("No substrings found.\n");
	}

	return 0;
}
