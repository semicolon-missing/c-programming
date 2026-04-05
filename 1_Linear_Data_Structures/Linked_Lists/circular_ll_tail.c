//Using only a tail pointer
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
	struct Node* next;
}Node;

Node* tail = NULL;

Node* create_node(int value){
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Memory Allocation Failed\n");
		return NULL;
	}
	new_node->key = value;
	new_node->next = NULL;
	return new_node;
}

void free_list() {
	if (tail == NULL) return;
	Node* current = tail->next;
	Node* next_node;
	while (current != tail) {
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(tail);
	tail = NULL;
}

void create(){
	int choice = 1;
	int value;
	free_list();
	while (choice == 1) {
		printf("Enter data: ");
		scanf("%d", &value);

		Node* new_node = create_node(value);
		if (new_node == NULL) return;
		
		if (tail == NULL) {
			tail = new_node;
			tail->next = new_node;	
		}
		else {
			new_node->next = tail->next;
			tail->next = new_node;
			tail = new_node;
		}
		printf("Do you want to continue? (1 for yes, 0 for no): ");
		scanf("%d", &choice);
	}
}

void display(){
	if (tail == NULL) {
		printf("List is empty\n");
	}
	else {
		Node* temp = tail->next;
		printf("List: ");
		do {
			printf("%d -> ", temp->key);
			temp = temp->next;
		} while (temp != tail->next);
		printf("(head)\n");
	}
}

void insert_at_start(int data){
	Node* new_node = create_node(data);
	if (new_node == NULL) return;
	if (tail == NULL) {
		tail = new_node;
		tail->next = new_node;
	}
	else{
		new_node->next = tail->next;
		tail->next = new_node;
	}
}

void insert_at_end(int data){
	Node* new_node = create_node(data);
	if (new_node == NULL) return;
	if(tail == NULL){
		tail = new_node;
		tail->next = new_node;
	}
	else {
		new_node->next = tail->next;
		tail->next = new_node;
		tail = new_node;
	}
}

int node_count(){
	if (tail == NULL) return 0;
	Node* temp = tail->next;
	int count = 0;
	do {
		count++;
		temp = temp->next;
	}while (temp != tail->next);
	return count;
}

void insert_at_pos(int data, int position){
	int length = node_count();
	if (position < 1 || position > length + 1){
		printf("Invalid position\n");
		return;
	}
	if(position == 1){
		insert_at_start(data);
	}
	else if (position == length + 1){
		insert_at_end(data);
	}
	else{
		Node* new_node = create_node(data);
		if (new_node == NULL) return;
		Node* temp = tail->next;
		int i = 1;
		while(i < position - 1){
			temp = temp->next;
			i++;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
}

void delete_at_start(){
	if (tail == NULL) {
		printf("List is empty\n");
	}
	else if (tail->next == tail){
		Node* temp = tail;
		tail = NULL;
		free(temp);
	}
	else {
		Node* temp = tail->next;
		tail->next = temp->next;
		free(temp);
	}	
}

void delete_at_end(){
	if (tail == NULL) {	
		printf("List is empty\n");
	}
	else if (tail->next == tail) {
		Node* temp = tail;
		tail = NULL;
		free(temp);
	}
	else{
		Node* current = tail->next;
		Node* previous = NULL;
		while (current->next != tail->next) {
			previous = current;
			current = current->next;
		}
		previous->next = tail->next;
		tail = previous;
		free(current);
	}
}

void delete_at_pos(int position){
	int length = node_count();
	if (position < 1 || position > length) {
		printf("Invalid position\n");
		return;
	}
	if (position == 1) {
		delete_at_start();
	}
	else if (position == length) {
		delete_at_end();
	}
	else{
		Node* current = tail->next;
		Node* next_node;
		int i = 1;
		while(i < position - 1){
			current = current->next;
			i++;
		}
		next_node = current->next;
		current->next = next_node->next;
		free(next_node);
	}
}

void reverse_list(){
	if (tail == NULL) {
		printf("List is empty\n");
		return;
	}
	if (tail->next == tail) return;

	Node* previous;
	Node* current;
	Node* next_node;
	current = tail->next;
	next_node = current->next;
	
	while (current != tail) {
		previous = current;
		current = next_node;
		next_node = current->next;
		current->next = previous;
	}
	next_node->next = tail;
	tail = next_node;
}

int main() {
	int choice, data, position;
	while (1) {
		printf("\n--- Circular Linked List Menu ---\n");
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
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter data: ");
				scanf("%d", &data);
				insert_at_start(data);
				break;
			case 4:
				printf("Enter data: ");
				scanf("%d", &data);
				insert_at_end(data);
				break;
			case 5:
				printf("Enter data: ");
				scanf("%d", &data);
				printf("Enter position: ");
				scanf("%d", &position);
				insert_at_pos(data, position);
				break;
			case 6:
				delete_at_start();
				break;
			case 7:
				delete_at_end();
				break;
			case 8:
				printf("Enter position: ");
				scanf("%d", &position);
				delete_at_pos(position);
				break;
			case 9:
				reverse_list();
				break;
			case 10:
				printf("Node count: %d\n", node_count());
				break;
			case 11:
				free_list();
				printf("List cleared.\n");
				break;
			case 12:
				free_list();
				exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}
	return 0;
}
