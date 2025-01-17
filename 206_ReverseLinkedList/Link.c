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
    // Can we think these as 4 unit change value instead we typically see 3?
    while (current->next != NULL)
    {
        // can we think the next NODE is not going to be used, so we save the current -> next 
        next = current->next; 
        // then we change the current -> next to point to the previous node
        current->next = prev;

        // then we update the previous node to be the current node
        prev = current;
        // then we update the current node to be the next node, which is the current -> next
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
