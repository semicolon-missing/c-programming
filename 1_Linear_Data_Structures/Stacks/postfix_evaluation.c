#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1) stack[++top] = x;
}

int pop() {
    if (top == -1) return 0;
    return stack[top--];
}

void evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        // 1. Push operands to the stack (converting char digit to integer)
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } 
        // 2. On operator, pop top two operands, evaluate, and push the result
        else {
            int val1 = pop(); // Top element (right operand)
            int val2 = pop(); // Second top element (left operand)
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    // 3. The final result is the remaining element in the stack
    printf("Result of evaluation: %d\n", pop());
}

int main() {
    // Equivalent to the infix expression: (8 + 2) * (5 - 3)
    char exp[] = "82+53-*"; 
    printf("Postfix expression: %s\n", exp);
    evaluatePostfix(exp);
    return 0;
}