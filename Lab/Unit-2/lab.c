/*Write a program to sum all the numbers from 1 to 100 except those divisible by 5.*/
#include <stdio.h>
int main(){
    int sum = 0;
    for (int i = 1; i <= 100; i++){
        if (i % 5 == 0){
            continue;
        }
        sum += i;
    }
    printf("The sum of all numbers between 1 & 100 except those divisible by 5 is %d\n.", sum);
    return 0;
}


