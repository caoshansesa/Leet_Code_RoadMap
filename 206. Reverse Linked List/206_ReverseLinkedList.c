#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    // implementation of reverseList function
}

void test_reverse_list_multiple_nodes() {
    // create a linked list with multiple nodes
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    node1->val = 1;
    node1->next = node2;
    node2->val = 2;
    node2->next = node3;
    node3->val = 3;
    node3->next = NULL;
    
    // call the reverseList function
    struct ListNode* reversedList = reverseList(node1);
    
    // assert the reversed list values
    assert(reversedList->val == 3);
    assert(reversedList->next->val == 2);
    assert(reversedList->next->next->val == 1);
    
    // free the memory allocated for the linked list
    free(node1);
    free(node2);
    free(node3);
}
