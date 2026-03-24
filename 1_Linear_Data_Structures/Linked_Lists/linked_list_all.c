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
void display_list(node* head) {
    if (head == NULL) {
        printf("List: NULL\n");
        return;
    }
    printf("List: ");
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to count total nodes
int node_count(node* head) {
    int count = 0;
    node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free memory
void free_list(node* head) {
    node *temp = head;
    while (temp != NULL) {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
}

// INSERTION OPERATIONS

// Insert at the start
node* insert_at_start(node* head, int value) {
    node *new_node = create_node(value);
    if (new_node == NULL) return head;

    new_node->next = head;
    return new_node; // Return new head
}

// Insert at the end
node* insert_at_end(node* head, int value) {
    node *new_node = create_node(value);
    if (new_node == NULL) return head;

    if (head == NULL) {
        return new_node;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Insert after a given position
node* insert_at_pos(node* head, int pos, int value) {
    int count = node_count(head);
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position %d\n", pos);
        return head;
    }

    if (pos == 1) {
        return insert_at_start(head, value);
    }

    node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    node *new_node = create_node(value);
    if (new_node == NULL) return head;

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// DELETION OPERATIONS

// Delete from start
node* delete_at_start(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return head; // Return new head
}

// Delete from end
node* delete_at_end(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node *temp = head;
    node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

// Delete at a specific position
node* delete_at_pos(node* head, int pos) {
    int count = node_count(head);
    if (pos < 1 || pos > count) {
        printf("Invalid position %d\n", pos);
        return head;
    }

    if (pos == 1) {
        return delete_at_start(head);
    }

    node *temp = head;
    node *prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// REVERSAL OPERATION

// Reverse the linked list
node* reverse_list(node* head) {
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // New head
}

int main() {
    node *head = NULL;

    printf("--- Insertion Operations ---\n");
    head = insert_at_start(head, 10);
    head = insert_at_start(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_pos(head, 2, 15);
    display_list(head);
    printf("Node count: %d\n", node_count(head));

    printf("\n--- Reversal Operation ---\n");
    head = reverse_list(head);
    display_list(head);

    printf("\n--- Deletion Operations ---\n");
    head = delete_at_start(head);
    display_list(head);
    head = delete_at_end(head);
    display_list(head);
    head = delete_at_pos(head, 2);
    display_list(head);

    printf("\n--- Final Node count: %d ---\n", node_count(head));
    free_list(head);

    return 0;
}
