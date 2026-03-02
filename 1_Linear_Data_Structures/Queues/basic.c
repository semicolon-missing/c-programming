#include <stdio.h>

#define MAX 8

int q[MAX], rear = -1, front = -1;

void enqueue(int val)
{
    if ((rear + 1) % MAX == front)
        return;

    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    q[rear] = val;
} 

int dequeue(){
    if 
}

int main()
{

    return 0;
}