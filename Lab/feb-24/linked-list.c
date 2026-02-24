#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

// Linear Search 
int linear_search(node *head, int key){
    while (head != NULL)
    {
        if (head->value == key)
            return 1;
        head = head->next;
    }

    return 0;
}
//Inserting element at the start
node* insert_at_start(node *head, int data){
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) return head;
    new_node->value = data;
    new_node->next = head;
    return new_node;
}
//Inserting element at the end
node* insert_at_end(node *head, int data){
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) return head;
    new_node->value = data;
    new_node->next = NULL;
    
    if (head == NULL) return new_node;
    
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}


//Insert after an element
node* insert_after(node *head, int target, int data) {
    node *temp = head;
    while (temp != NULL && temp->value != target) {
        temp = temp->next;
    }

    if (temp != NULL) {
        node *new_node = (node *)malloc(sizeof(node));
        if (new_node == NULL) return head;
        new_node->value = data;
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("Target element %d not found in the list.\n", target);
    }
    return head;
}

//Insert before an element
node* insert_before(node *head, int target, int data) {
    if (head == NULL) return head;

    if (head->value == target) {
        return insert_at_start(head, data);
    }

    node *temp = head;
    while (temp->next != NULL && temp->next->value != target) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        node *new_node = (node *)malloc(sizeof(node));
        if (new_node == NULL) return head;
        new_node->value = data;
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("Target element %d not found in the list.\n", target);
    }
    return head;
}


//Printing the list
void print_list(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;
    head = insert_at_start(head, 10);
    head = insert_at_start(head, 20);
    head = insert_at_end(head, 30);
    
    printf("Initial list: ");
    print_list(head);
    
    printf("Inserting 15 after 10:\n");
    head = insert_after(head, 10, 15);
    print_list(head);

    printf("Inserting 5 before 20:\n");
    head = insert_before(head, 20, 5);
    print_list(head);

    printf("Inserting 25 before 30:\n");
    head = insert_before(head, 30, 25);
    print_list(head);
    
    if (linear_search(head, 20)) {
        printf("Element 20 found\n");
    } else {
        printf("Element 20 not found\n");
    }

    return 0;
}