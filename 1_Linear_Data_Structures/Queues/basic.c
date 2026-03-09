#include <stdio.h>

#define MAX 8

int queue[MAX];
int rear = -1;
int front = -1;


//Enqueue function
void enqueue(int val)
{
    if (rear == -1 && front == -1){
        rear++;
        front++;
        queue[rear] = val;
    }

    else if(rear == MAX - 1){
        printf("Overflow\n");
    }

    else {
        rear++;
        queue[rear] = val;
    }
}

//Dequeue Function
void dequeue(){
    if (front == -1){
        printf("Underflow\n");
    }

    else if(front == rear){
        printf("Dequeued element = %d\n", queue[front]);
        front = -1;
        rear = -1;
    }

    else {
        printf("Dequeued element = %d\n", queue[front]);
        front++;
    }
}

void peek(){
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }

    else{
        printf("%d\n", queue[front]);
    }
    
}

//Display function
void display(){
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue is: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    dequeue();
    display();
    
    enqueue(40);
    display();

    return 0;
}