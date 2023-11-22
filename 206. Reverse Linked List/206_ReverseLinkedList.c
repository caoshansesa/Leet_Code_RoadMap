#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to reverse a linked list
struct Node *reverseLinkedList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        // Store the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move pointers one step ahead
        prev = current;
        current = next;
    }

    // 'prev' now points to the new head
    return prev;
}

// Function to print a linked list
void printLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create a sample linked list
    struct Node *head = NULL;
    for (int i = 5; i >= 1; i--)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    printf("Original linked list: ");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("Reversed linked list: ");
    printLinkedList(head);

    // Free the memory
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

