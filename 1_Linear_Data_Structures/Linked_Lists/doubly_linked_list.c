#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

//Function to create a node
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node) {
    perror("Failed to allocate memory for node");
    return NULL;
  }
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}


void append(Node **head, int data) {
  Node *new_node = create_node(data);
  if (!new_node)
    return;

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
  new_node->prev = temp;
}

//Function to print the list
void print_list(const Node *head) {
  printf("List: ");
  const Node *temp = head;
  while (temp != NULL) {
    printf("%d %s", temp->data, temp->next ? "<-> " : "");
    temp = temp->next;
  }
  printf("NULL\n");
}

void free_list(Node **head) {
  Node *current = *head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}
//INSERTIONS

//1. Insert at start
void insert_at_start(Node **head, int data) {
  Node *new_node = create_node(data);
  if (!new_node)
    return;
  if (*head == NULL) {
    *head = new_node;
  } else {
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
  }
}

//2. Insert at end
void insert_at_end(Node **head, int data) {
  Node *new_node = create_node(data);
  if (!new_node)
    return;
  if (*head == NULL) {
    *head = new_node;
  } else {
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    new_node->prev = temp;
    temp->next = new_node;
  }
}

//3. Insert after a position
void insert_after_pos(Node **head, int data, int position) {
  if (*head == NULL) {
    printf("List is empty. Cannot insert after a position.\n");
    return;
  }
  if (position < 1) {
    printf("Invalid position.\n");
    return;
  }

  Node *temp = *head;
  int count = 1;
  while (count < position && temp != NULL) {
    temp = temp->next;
    count++;
  }

  if (temp == NULL) {
    printf("Position %d out of bounds.\n", position);
    return;
  }

  Node *new_node = create_node(data);
  if (!new_node)
    return;

  new_node->next = temp->next;
  new_node->prev = temp;
  if (temp->next != NULL) {
    temp->next->prev = new_node;
  }
  temp->next = new_node;
}

//4. Insert before a position
void insert_before_pos(Node **head, int data, int position) {
  if (position < 1) {
    printf("Invalid position.\n");
    return;
  }
  if (position == 1) {
    insert_at_start(head, data);
    return;
  }
  if (*head == NULL) {
    printf("List is empty. Cannot insert at position %d.\n", position);
    return;
  }

  Node *temp = *head;
  int count = 1;
  while (count < position && temp != NULL) {
    temp = temp->next;
    count++;
  }

  if (temp == NULL) {
    printf("Position %d out of bounds.\n", position);
    return;
  }

  Node *new_node = create_node(data);
  if (!new_node)
    return;

  new_node->next = temp;
  new_node->prev = temp->prev;
  if (temp->prev != NULL) {
    temp->prev->next = new_node;
  }
  temp->prev = new_node;
}

//DELETIONS

//1. Delete at start
void delete_at_start(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  if (*head != NULL) {
    (*head)->prev = NULL;
  }
  free(temp);
}

//2. Delete at end
void delete_at_end(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = *head;
  if (temp->next == NULL) {
    *head = NULL;
    free(temp);
    return;
  }
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
}

//3. Delete at a position
void delete_at_pos(Node **head, int position) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }
  if (position == 1) {
    delete_at_start(head);
    return;
  }

  Node *temp = *head;
  int count = 1;
  while (count < position && temp != NULL) {
    temp = temp->next;
    count++;
  }

  if (temp == NULL) {
    printf("Position %d out of bounds\n", position);
    return;
  }

  if (temp->next != NULL) {
    temp->next->prev = temp->prev;
  }
  if (temp->prev != NULL) {
    temp->prev->next = temp->next;
  }
  free(temp);
}

//REVERSAL
void reverse_list(Node **head) {
  if (*head == NULL || (*head)->next == NULL) {
    return;
  }
  Node *current = *head;
  Node *temp = NULL;

  while (current != NULL) {
    // Swap next and prev pointers
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;

    // Move to next node (which is prev because of swap)
    current = current->prev;
  }

  // Update head to the last node processed
  if (temp != NULL) {
    *head = temp->prev;
  }
}

// Function to count nodes
int node_count(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

// Function to create a list with multiple nodes
void create_list(Node **head) {
  int choice = 1;
  int data;
  free_list(head);
  while (choice == 1) {
    printf("Enter data: ");
    scanf("%d", &data);
    insert_at_end(head, data);
    printf("Do you want to continue? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
  }
}

int main() {
  Node *head = NULL;
  int choice, data, position;
  while (1) {
    printf("\n--- Doubly Linked List Menu ---\n");
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
        create_list(&head);
        break;
      case 2:
        print_list(head);
        break;
      case 3:
        printf("Enter data: ");
        scanf("%d", &data);
        insert_at_start(&head, data);
        break;
      case 4:
        printf("Enter data: ");
        scanf("%d", &data);
        insert_at_end(&head, data);
        break;
      case 5:
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter position: ");
        scanf("%d", &position);
        insert_before_pos(&head, data, position);
        break;
      case 6:
        delete_at_start(&head);
        break;
      case 7:
        delete_at_end(&head);
        break;
      case 8:
        printf("Enter position: ");
        scanf("%d", &position);
        delete_at_pos(&head, position);
        break;
      case 9:
        reverse_list(&head);
        break;
      case 10:
        printf("Node count: %d\n", node_count(head));
        break;
      case 11:
        free_list(&head);
        printf("List cleared.\n");
        break;
      case 12:
        free_list(&head);
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}