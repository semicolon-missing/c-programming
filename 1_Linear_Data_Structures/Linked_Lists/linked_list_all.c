#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *next;
} node;

// Function to create a single node
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

// Function to create a list with multiple nodes
node* create_list(node* head) {
    int choice = 1;
    int value;
    free_list(head);
    head = NULL;
    while (choice == 1) {
        printf("Enter data: ");
        scanf("%d", &value);
        head = insert_at_end(head, value);
        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }
    return head;
}

int main() {
    node *head = NULL;
    int choice, data, position;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Start\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete at Start\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Position\n");
        printf("9. Reverse List\n");
        printf("10. Count Nodes\n");
        printf("11. Free List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                head = create_list(head);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_at_start(head, data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_at_end(head, data);
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insert_at_pos(head, position, data);
                break;
            case 6:
                head = delete_at_start(head);
                break;
            case 7:
                head = delete_at_end(head);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &position);
                head = delete_at_pos(head, position);
                break;
            case 9:
                head = reverse_list(head);
                break;
            case 10:
                printf("Node count: %d\n", node_count(head));
                break;
            case 11:
                free_list(head);
                head = NULL;
                printf("List cleared.\n");
                break;
            case 12:
                free_list(head);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
