#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int key;
    struct node* prev;
    struct node* next;
}node;

node* head;

void create(){
    node* temp;

    while(choice == 1){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node==NULL){
        printf("Memory allocation failed.")
    }
    printf("Enter a data: ");
    scanf("%d", new_node->key);
    
    new_node->prev = NULL;
    new_node->next = NULL;

    if(head == NULL){
        head = temp = new_node;
    }
    else{
        temp->next = new_node;
        new_node->prev = temp;
        temp = new_node;
    }

    }
    
}

int main(){

}