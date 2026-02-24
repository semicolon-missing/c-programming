#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) stack[++top] = x;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp) {
    char postfix[MAX];
    int j = 0;
    
    for (int i = 0; exp[i] != '\0'; i++) {
        // 1. Operands go directly to the postfix output
        if (isalnum(exp[i])) {
            postfix[j++] = exp[i];
        } 
        // 2. Push '(' onto the stack
        else if (exp[i] == '(') {
            push(exp[i]);
        } 
        // 3. On ')', pop operators to output until '(' is found
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } 
        // 4. On operator, pop higher or equal precedence operators, then push
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                postfix[j++] = pop();
            }
            push(exp[i]);
        }
    }
    
    // 5. Pop all remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char exp[] = "(A+B)*(C-D)";
    printf("Infix expression:   %s\n", exp);
    infixToPostfix(exp);
    return 0;
}