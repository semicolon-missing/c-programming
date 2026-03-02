#include <stdio.h>

int charToInt(char c){
	return c - '0';
}

int interpret(char expression[]){
	int result = charToInt(expression[0]);
	int i = 1;
	while (expression[i] != '\0'){
		char operator = expression[i];
		//The Character immediately after the operator is the next number.
		int nextNumber = charToInt(expression[i + 1]);

		//Apply the operation
		if (operator == '+'){
			result = result + nextNumber;
		} else if (operator == '-'){
			result = result - nextNumber;
		}

		i = i + 2;
	}
	return result;
}

int main() {
	char input[100];

	printf("Enter an expression (e.g., 3+5-4+7-6): ");
	scanf("%s", input);

	int finalResult = interpret(input);

	printf("Output: %d\n", finalResult);

	return 0;
}

