#include <stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

//Enqueue function in a circular queue
void enqueue(int x){
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }

    else if ((rear + 1)%N == front)
    {
        printf("Overflow\n");
    }
    
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
    
}

// Dequeue function in a circular queue
void dequeue(){
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    
    else if(front == rear)
    {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }

    else {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

//Display function
void display(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }

    else{
        int i = front;
        printf("Queue is: \n");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;

        }
        printf("%d\n", queue[rear]);
    }
    
}

void peek(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else{
        printf("%d\n", queue[front]);
    }
}

int main() {
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();

    return 0;
}