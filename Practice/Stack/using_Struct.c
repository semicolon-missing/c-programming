#include <stdio.h>
#define MAX 20

typedef struct{
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *stack){
    stack->top = -1;
}

int isFull(Stack *stack){
    return stack->top >= MAX - 1;
}

int isEmpty(Stack *stack){
    return stack->top == -1;
}


void push(Stack *stack, int value){
    if(isFull(stack)){
        printf("Stack Overflow!\n");
        return;
    }
    else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }

}

int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int main() {
    Stack myStack;
    initStack(&myStack);
    push(&myStack, 10);
    printf("Popped: %d\n", pop(&myStack));

    return 0;
}