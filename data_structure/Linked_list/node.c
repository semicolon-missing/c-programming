#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *get_node(int value)
{
    node *n1 = (node *)malloc(sizeof(node));
    if (n1 == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n1->value = value;
    n1->next = NULL;
    return n1;
}

int main()
{
    int n, i, val;
    node *head = NULL, *curr = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        node *newNode = get_node(val);
        if (head == NULL)
        {
            head = newNode;
            curr = head;
        }
        else
        {
            curr->next = newNode;
            curr = curr->next;
        }
    }

    printf("Linked List: ");
    curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");

    return 0;
}