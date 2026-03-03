#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *next;
} node;

// Function to count total nodes
int node_count(node* head){
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to create a linked list
void create_list(node** head){
    int choice = 1;
    node *temp = *head;

    // Move temp to the end of the list if it already exists
    if (temp != NULL) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }

    while (choice)
    {
        node *new_node = (node *)malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Memory Allocation Failed\n");
            return;
        }
        
        printf("Enter a value:\n");
        scanf("%d", &new_node->key);
        new_node->next = NULL;

        if (*head == NULL)
        {
            *head = temp = new_node;
        }
        else{
            temp->next = new_node;
            temp = new_node;
        }

        printf("Continue (1 for yes, 0 for no)?\n");
        scanf("%d", &choice);
    } 
}

// Function to print the linked list
void display_list(node* head) {
    if (head == NULL) {
        printf("Linked list: NULL\n");
        return;
    }
    printf("Linked list: ");
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Deletion at the start
void delete_from_start(node** head){
    if (*head == NULL)
    {
        printf("List is empty.\n");
    }
    else{
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Deletion from end
void delete_at_end(node** head){
    if (*head == NULL)
    {
        printf("List is Empty\n");
    }
    else {
        node *temp = *head;
        node *previous_node = NULL;

        while (temp->next != NULL)
        {
            previous_node = temp;
            temp = temp->next;
        }
        if (*head == temp){
            *head = NULL;
        }
        else {
            previous_node->next = NULL;
        }
        free(temp);
    }
}

// Deletion at a specific position
void delete_at_pos(node** head, int pos){
    int count = node_count(*head);
    if (pos <= 0 || pos > count)
    {
        printf("Invalid Position %d\n", pos);
        return;
    }
    
    if (pos == 1) {
        delete_from_start(head);
        return;
    }

    node *temp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

int main() {
    node *head = NULL;
    
    printf("Creating Initial List:\n");
    create_list(&head);
    display_list(head);

    printf("\nDeleting from start:\n");
    delete_from_start(&head);
    display_list(head);

    printf("\nDeleting from end:\n");
    delete_at_end(&head);
    display_list(head);

    printf("\nDeleting at position 2 (if exists):\n");
    delete_at_pos(&head, 2);
    display_list(head);

    return 0;
}