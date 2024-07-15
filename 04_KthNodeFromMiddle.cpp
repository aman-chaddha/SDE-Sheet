#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findBthFromMiddle(ListNode* A, int B) {
    // Step 1: Determine the length of the linked list
    int length = 0;
    ListNode* temp = A;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Step 2: Find the position of the middle node
    int middlePos = (length / 2) + 1;

    // Step 3: Calculate the target position from the start (1-based index)
    int targetPos = middlePos - B;

    // Step 4: Check if the target position is valid
    if (targetPos <= 0) {
        return -1;
    }

    // Step 5: Traverse the linked list to find the target node
    temp = A;
    for (int i = 1; i < targetPos; ++i) {
        temp = temp->next;
    }

    return temp->val;
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(3);
    head->next = new ListNode(4);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(15);
    head->next->next->next->next->next->next->next = new ListNode(61);
    head->next->next->next->next->next->next->next->next = new ListNode(16);

    int B = 3;
    cout << "The " << B << "-th node from the middle towards the head is: " << findBthFromMiddle(head, B) << endl;

    return 0;
}
