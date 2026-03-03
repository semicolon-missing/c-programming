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

//Function to insert at the end
node* insert_at_end(node** head, int value){
    node *new_node = create_node(value);
    if (*head == NULL)
    {
        *head = new_node;
        return new_node;
    }
    
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
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

//Function to insert after a given position
node* insert_after_pos(node** head, int pos, int value){
    if (pos > node_count(*head))
    {
        printf("Invalid position\n");
    }
    else{
        node *temp = *head;
        int i = 1;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        node *new_node = create_node(value);
        if (new_node == NULL) {
        return NULL;
        }
        new_node->key = value;
        new_node->next = temp->next;
        temp->next = new_node;  
    }
    

}

int main() {
    node *head = NULL;

    insert_at_start(&head, 20);
    insert_at_start(&head, 40);
    insert_at_start(&head, 35);
    print_ll(head);
    insert_at_end(&head, 32);
    insert_at_end(&head, 240);
    print_ll(head);
    insert_after_pos(&head, 3, 29);
    print_ll(head);
    insert_after_pos(&head, 2, 39);
    print_ll(head);
    free_ll(head);

    return 0;
}