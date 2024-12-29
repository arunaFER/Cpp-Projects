/*
Reverse Linked List: Easy

Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr){
        ListNode* temp = curr->next;

        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
 }

 ListNode* recursionReverseList(ListNode* head){
    if (!head || !head->next){ // if list is empty or contains single node
        return head;
    }

    ListNode* newHead = recursionReverseList(head->next);

    // ListNode* m->next = head->next;
    // m->next = head;
    // or

    head->next->next = head; 
    head->next = nullptr;

    return newHead;
 }


 void printList(ListNode* head){
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
 }

 int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    std::cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    ListNode* reversedHead = reverseList(head);

    // Print reversed list
    std::cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}



