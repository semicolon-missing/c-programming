#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

Node* create_node(int data){
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Memory allocation failed\n");
		return NULL;
	}
	new_node->key = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

void free_list() {
	if (head == NULL) return;
	Node* temp = head;
	do {
		Node* next_node = temp->next;
		free(temp);
		temp = next_node;
	} while (temp != head);
	head = tail = NULL;
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
		if (head == NULL) {
			head = tail = new_node;
			head->next = head;
			head->prev = head;
		}
		else {
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
			new_node->next = head;
			head->prev = new_node;
		}
		printf("Continue?(Enter 1 for yes, 0 for no): ");
		scanf("%d", &choice);
	}
}

void display(){
	if (head == NULL) {
		printf("List is empty\n");
	}
	else {
		Node* temp = head;
		printf("List: ");
		do {
			printf("%d -> ", temp->key);
			temp = temp->next;
		} while (temp != head);
		printf("(head)\n");
	}
}

void insert_at_start(int data){
	Node* new_node = create_node(data);
	if (new_node == NULL) return;
	if (head == NULL) {
		head = tail = new_node;
		head->next = head;
		head->prev = head;
	}
	else{
		new_node->next = head;
		head->prev = new_node;
		new_node->prev = tail;
		tail->next = new_node;
		head = new_node;
	}
}

void insert_at_end(int data){
	Node* new_node = create_node(data);
	if (new_node == NULL) return;
	if (head == NULL) {
		head = tail = new_node;
		head->next = head;
		head->prev = head;
	}
	else{
		new_node->prev = tail;
		tail->next = new_node;
		new_node->next = head;
		head->prev = new_node;
		tail = new_node;
	}
}

int node_counting(){
	if (head == NULL) return 0;
	int count = 0;
	Node* temp = head;
	do {
		count++;
		temp = temp->next;
	} while (temp != head);
	return count;
}

void insert_at_pos(int data, int position){
	int count = node_counting();
	if (position < 1 || position > count + 1) {
		printf("Invalid position\n");
		return;
	}
	if (position == 1) {
		insert_at_start(data);
	} else if (position == count + 1) {
		insert_at_end(data);
	} else {
		Node* new_node = create_node(data);
		if (new_node == NULL) return;
		Node* temp = head;
		for (int i = 1; i < position - 1; i++) {
			temp = temp->next;
		}
		new_node->next = temp->next;
		new_node->prev = temp;
		temp->next->prev = new_node;
		temp->next = new_node;
	}
}

void delete_at_start(){
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	Node* temp = head;
	if (head == tail) {
		head = tail = NULL;
	} else {
		head = head->next;
		head->prev = tail;
		tail->next = head;
	}
	free(temp);
}

void delete_at_end(){
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	Node* temp = tail;
	if (head == tail) {
		head = tail = NULL;
	} else {
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
	}
	free(temp);
}

void delete_at_pos(int position){
	int count = node_counting();
	if (position < 1 || position > count) {
		printf("Invalid position\n");
		return;
	}
	if (position == 1) {
		delete_at_start();
	} else if (position == count) {
		delete_at_end();
	} else {
		Node* temp = head;
		for (int i = 1; i < position; i++) {
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
}

void reverse_list(){
	if (head == NULL || head == tail) return;
	Node* current = head;
	Node* temp = NULL;
	do {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev; // Move to next node (which is now prev)
	} while (current != head);
	
	temp = head;
	head = tail;
	tail = temp;
}

int main() {
	int choice, data, position;
	while (1) {
		printf("\n--- Doubly Circular Linked List Menu ---\n");
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
				printf("Node count: %d\n", node_counting());
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
