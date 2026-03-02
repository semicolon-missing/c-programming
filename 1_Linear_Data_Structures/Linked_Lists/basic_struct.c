#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char Name[20];
    int Age;
    int Roll_Number;
}Record;

int main() {
    Record * S1;
    S1 = (Record *)malloc(sizeof(Record));

    strcpy(S1->Name, "Vivek");
    S1->Age = 18;
    S1->Roll_Number = 25293916123;

    printf("Name: %c\n", S1->Name);
    printf("Age: %d\n", S1->Age);

    return 0;
}