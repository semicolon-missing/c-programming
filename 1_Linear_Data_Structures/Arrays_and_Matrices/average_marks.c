//A c program to calulate mean marks and print horizontal histogram showing each student's marks as a line of stars.

#include <stdio.h>

int main() {
	int marks[] = {35, 45, 94, 67, 81, 29};
	float mean_marks;	
	float sum = 0;
	int size = sizeof(marks) / sizeof(marks[0]);

       	// Calaculating mean marks
	for (int i = 0; i < size; i++){
		sum += marks[i];
	}

	mean_marks = sum / size;
	
	// Calculate the position of mean in terms of stars(1 star = 2 points)
	int mean_posit = mean_marks / 2;
	
	printf("Marks Histogram (Mean marked with '#')\n");
	printf("--------------------------------------\n");
	
	for (int i = 0; i < size; i++){
		int star_count = marks[i] / 2;

		//Determining the length of the line to be printed
		int line_length = (star_count > mean_posit) ? star_count : mean_posit;
		// Print the line character by character
		for (int j = 1; j <= line_length; j++) {
			if (j == mean_posit){
				printf("#");
			} else if (j <= star_count){
				printf("*");
			} else {
				printf(" ");
			}




		} 
		printf("\n");
	}
    
	printf("----------------------------------------\n");
	printf("Mean Mark: %.2f\n", mean_marks);

    return 0;
}

