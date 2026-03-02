/*Name - Vivek Kumar Pandey
Date - 25/11/2025
Program Description - Write a program to sum all the numbers from 1 to 100 except those divisible by 5.*/
#include <stdio.h>

int main() {
    // Initialize sum to 0
    int sum = 0;

    // Loop through numbers from 1 to 100
    for (int i = 1; i <= 100; i++) {
        // Check if the number is divisible by 5
        if (i % 5 == 0) {
            // If divisible by 5, skip this iteration
            continue;
        }
        // Add the number to the sum
        sum += i;
    }

    // Print the final result
    printf("The sum of all numbers between 1 & 100 except those divisible by 5 is %d\n.", sum);
    return 0;
}