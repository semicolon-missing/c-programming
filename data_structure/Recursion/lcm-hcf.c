#include <stdio.h>

int hcf_recursive(int a, int b){
    if (b == 0)
        return a;
    else
        return hcf_recursive(b, b % a);
}

int lcm_recursive(int a, int b){
    return (a * b) / hcf_recursive(a, b);
}

int main() {
    int a, b;
    printf("Enter two integers:\n");
    scanf("%d %d", &a, &b);
    printf("HCF of %d and %d is: %d\n", a, b, hcf_recursive(a, b));
    printf("LCM of %d and %d is: %d\n", a, b, lcm_recursive(a, b));
    
    return 0;
}