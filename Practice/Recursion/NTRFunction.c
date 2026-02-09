#include <stdio.h>

void NTR(int i){
    if (i <= 0)
    {
        printf(" ");
    }
    else {
        NTR(i - 1);
        printf("%d", i);
        NTR(i - 1);
    }
    
}

int main() {
    NTR(3);
    return 0;
}