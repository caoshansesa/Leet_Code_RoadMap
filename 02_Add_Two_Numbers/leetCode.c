/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    int val;
    struct ListNode* next; // watch this type
} Node;

void addNodeToList(struct ListNode** head, int val)
{
    Node* new_node =  (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Allocate Memory Error");   /* code */
        return;
    }
    // prepare the new node
    new_node->next = NULL;
    new_node->val = val;

    if(*head == NULL) // if head is empty, which means this is the first node
    {
        // make the new_node as the head
        *head = new_node;
    }
    else // The Link list is not null, attach the new node to the list
    {
        // We should travel to the end of the LinkList, and add the new node to the end of the LinkList
        // or it will break the LinkList in middle if current head is not the last one.
        Node* lastNodeInLinkList = *head;
        while(lastNodeInLinkList->next != NULL)
        {
         lastNodeInLinkList = lastNodeInLinkList->next;
        }
        // We find the last node of the List
        lastNodeInLinkList->next = new_node;  
    }

}

void printList(struct ListNode* head) 
{
    if(head == NULL)
    {
        printf("The LinkList is empty");
    }
    else
    {
        while(head != NULL)
        {
            printf("Link address: %p, value: %d\n", head, head->val);
            head = head->next;
        }
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}

int main()
{
    struct ListNode* head = NULL;
    addNodeToList(&head, 1);
    addNodeToList(&head, 2);
    addNodeToList(&head, 3);
    addNodeToList(&head, 4);
    addNodeToList(&head, 5);
    printList(head);
}