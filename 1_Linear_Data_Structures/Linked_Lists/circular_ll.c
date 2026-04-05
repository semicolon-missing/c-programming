//Using both a head and a tail pointer
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
	struct Node* next;
}Node;

Node* head;
Node* tail;

Node* create_node(int value){
	Node* new_node = (Node*)malloc(sizeof(Node));
	if(new_node == NULL){
		printf("Memory Allocation Failed\n");
		return NULL;
	}
	new_node->key = value;
	new_node->next = NULL;
	return new_node;
}

void create(){
	head = NULL;
	int choice = 1;
	int value;
	while (choice == 1) {
		printf("Enter data: ");
		scanf("%d", &value);
		Node* new_node = create_node(value);
		if (head == NULL){
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
		tail->next = head;

		printf("Continue?(Press 1 for yes)");
		scanf("%d", &choice);
	}
}

void display(){
	if (head == NULL){
		printf("List is empty\n");
	}
	else{
		Node* temp = head;
		printf("List: ");
		while (temp->next != head) {
			printf("%d -> ", temp->key);	
			temp = temp->next;
		}
		printf("%d -> ", temp->key);
		printf("(head)\n");
	}
}


			
		
	



