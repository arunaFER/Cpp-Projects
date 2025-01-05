/*
Description:

Merge Two Sorted Linked Lists: Easy

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted linked list and return the head of the new sorted linked list.
The new list should be made up of nodes from list1 and list2.

Input: list1 = [1,2,4], list2 = [1,3,5]
Output: [1,1,2,3,4,5]

Input: list1 = [], list2 = [1,2]
Output: [1,2]

Input: list1 = [], list2 = []
Output: []

O(n + m) time and O(1) space
*/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


// Answer
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){

    ListNode dummy;
    ListNode* tail = &dummy;

    while(list1 && list2){
        if (list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1){
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
 }



 ListNode* createList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

// Main function to test mergeTwoLists
int main() {
    // Create test lists
    std::vector<int> list1Values = {1, 2, 4};
    std::vector<int> list2Values = {1, 3, 5};

    ListNode* list1 = createList(list1Values);
    ListNode* list2 = createList(list2Values);

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    // Merge the lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory (optional for demonstration purposes, but good practice)
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}