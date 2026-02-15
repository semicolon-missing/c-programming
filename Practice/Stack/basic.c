#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Check if stack is full
int isFull()
{
    return top == MAX - 1;
}

// Function to print all elements currently in the stack
void printStack()
{
    printf("Current Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Push element onto stack
void push(int val)
{
    if (isFull())
    {
        printf("Stack Overflow! Cannot push %d\n", val);
    }
    else
    {
        stack[++top] = val;
        printf("%d pushed to stack\n", val);
        printStack();
    }
}

// Remove element from stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    else
    {
        int val = stack[top--];
        printStack();
        return val;
    }
}

int main()
{
    // 1. Push elements
    push(10);
    push(20);
    push(30);
    push(45);
    push(75);

    // 2. Check full/empty status
    printf("Is stack full? %s\n", isFull() ? "Yes" : "No");

    // 3. Pop elements
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());

    // 4. Verify stack state after pops
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}