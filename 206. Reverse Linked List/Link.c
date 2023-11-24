#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkList
{
    int val;
    struct LinkList *next;
} Node;

void printLinkList(Node *inputList)
{
    Node *localList = inputList;
    while (localList->next != NULL)
    {
        printf("Current Address is %p", localList);
        printf("The value is %d", localList->val);
    }
}

Node* reverseLinkList(Node *inputLinkList)
{
    Node *prev = NULL;
    Node *current = inputLinkList;
    Node *next = NULL;
    while (current->next != NULL)
    {

        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    return prev; 
}

int main()
{

    // Create a sample linked list
    Node *head = NULL;
    for (int i = 5; i >= 1; i--)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = i;
        newNode->next = head;
        head = newNode;
    }

    printf("Original linked list: ");
    printLinkList(head);

    // Reverse the linked list
    head = reverseLinkList(head);

    printf("Reversed linked list: ");
    printLinkList(head);

    // Free the memory
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
