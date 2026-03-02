#include <stdio.h>

// Define the maximum size of the queue
#define N 5

/**
 * Inserts an element into the circular queue.
 * @param Q Pointer to the queue array
 * @param F Pointer to the front index
 * @param R Pointer to the rear index
 * @param size The maximum size of the queue
 * @param val The character value to insert
 */
void insert(char *Q, int *F, int *R, int size, char val) {
    // Check if the queue is full
    // In a circular queue, the next position after R being F indicates overflow
    if ((*R + 1) % size == *F) {
        printf("Queue Overflow\n");
        return;
    }
    
    // If the queue is empty, initialize F to 0
    if (*F == -1) {
        *F = 0;
    }
    
    // Increment R circularly and insert the value
    *R = (*R + 1) % size;
    Q[*R] = val;
}

/**
 * Deletes an element from the circular queue.
 * @return The deleted character, or -1 if underflow
 */
int deletion(char *Q, int *F, int *R, int size) {
    // Check if the queue is empty
    if (*F == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    char y = Q[*F];
    
    // If there was only one element, reset F and R to -1
    if (*F == *R) {
        *F = -1;
        *R = -1;
    } else {
        // Increment F circularly
        *F = (*F + 1) % size;
    }
    
    return y;
}

/**
 * Displays the current elements in the circular queue.
 */
void display(char *Q, int F, int R, int size) {
    if (F == -1) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Circular Queue: ");
    int i = F;
    while (1) {
        printf("%c ", Q[i]);
        if (i == R) break; // Reached the end of the queue
        i = (i + 1) % size; // Move to the next index circularly
    }
    printf("\n");
}

int main() {
    char Q[N];
    int F = -1, R = -1;

    // Test insertions
    insert(Q, &F, &R, N, 'A');
    insert(Q, &F, &R, N, 'B');
    insert(Q, &F, &R, N, 'C');
    insert(Q, &F, &R, N, 'D');
    insert(Q, &F, &R, N, 'E'); // Queue is now full (size 5)
    display(Q, F, R, N);

    // Test overflow
    insert(Q, &F, &R, N, 'F');

    // Test deletions
    int res;
    if ((res = deletion(Q, &F, &R, N)) != -1)
        printf("Deleted: %c\n", (char)res);
    if ((res = deletion(Q, &F, &R, N)) != -1)
        printf("Deleted: %c\n", (char)res);
    
    display(Q, F, R, N);

    // Test circular insertion
    insert(Q, &F, &R, N, 'X');
    display(Q, F, R, N);

    return 0;
}
