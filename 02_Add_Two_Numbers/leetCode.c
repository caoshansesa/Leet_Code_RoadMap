#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct LinkList{
    int data;
    struct LinkList *next;
} Node;

void printList(Node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void appendListList(Node **inputHead, int input_val)
{
    // Alocate the memory for the newly attached node
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = input_val;

    // if the input node is empty, make the new node the head
    if(*inputHead == NULL)
    {
        *inputHead = newNode;
    }
    else
    {
        Node *LastNodeofList = *inputHead;
        while(LastNodeofList->next != NULL)
        {
            LastNodeofList = LastNodeofList->next;
        }
        LastNodeofList->next = newNode;
    }

}
Node *AddLinkList(Node *head, Node *head2) {
    Node *result = NULL;
    Node *current = head;
    Node *current2 = head2;
    int carry = 0;

    while(current != NULL || current2 != NULL || carry != 0) {
        int sum = carry;
        if (current != NULL) {
            sum += current->data;
            current = current->next;
        }
        if (current2 != NULL) {
            sum += current2->data;
            current2 = current2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        appendListList(&result, sum);
    }
    return result;
}

int main()
{
    Node *head = NULL;
    appendListList(&head, 1);
    appendListList(&head, 2);
    appendListList(&head, 3);
    appendListList(&head, 4);
    appendListList(&head, 5);
    appendListList(&head, 6);
    appendListList(&head, 7);
    appendListList(&head, 8);

    Node *head2 = NULL;
    appendListList(&head2, 1);
    appendListList(&head2, 2);
    appendListList(&head2, 3);
    appendListList(&head2, 4);
    appendListList(&head2, 5);
    appendListList(&head2, 6);
    appendListList(&head2, 7);
    appendListList(&head2, 8);

    printf("List 1: ");
    printList(head);

    printf("List 2: ");
    printList(head2);

    Node *result = NULL;
    result = AddLinkList(head, head2);
    printf("Result: ");
    printList(result);

    // Free memory
    freeList(head);
    freeList(head2);
    freeList(result);
    return 0;
}
