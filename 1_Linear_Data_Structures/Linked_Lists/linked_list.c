#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}node;

void main(){
    node *head = NULL;
    node *temp = NULL;
    int choice = 1;

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

        if (head == NULL)
        {
            head = temp = new_node;
        }
        
        else{
            temp->next = new_node;
            temp = new_node;
        }

        printf("Continue(1 for yes, 0 for no)?\n");
        scanf("%d", &choice);
    }

    printf("Linked list:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("\n");
    
    //Freeing memory
    temp = head;
    while (temp != NULL)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
    
}
