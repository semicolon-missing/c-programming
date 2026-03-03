#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int key;
    struct node *next;
} node;

// Helper function to create a single node
node* create_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    new_node->key = value;
    new_node->next = NULL;
    return new_node;
}

// Function to print the linked list
void print_ll(node* head) {
    printf("Linked list: ");
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free memory
void free_ll(node* head) {
    node *temp = head;
    while (temp != NULL) {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
}

//Insert_at_start function
node* insert_at_start(node **head, int value) {
    node *new_node = create_node(value); // Using helper function
    if (new_node == NULL) {
        return NULL;
    }

    new_node->next = *head; // Point new node's next to current head
    *head = new_node;       // Update the head pointer to new node

    return new_node;
}

//Function to count total nodes
int node_count(node* head){
    int count;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    node *head = NULL;

    insert_at_start(&head, 20);
    insert_at_start(&head, 40);
    insert_at_start(&head, 35);
    print_ll(head);
    printf("The length of the linked list is %d\n", node_count(head));
    free_ll(head);
    
    return 0;
}