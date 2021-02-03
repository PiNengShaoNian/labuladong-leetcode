#include <cassert>
#include <iostream>

#include "ListNode.h"

using namespace std;

ListNode* startPointOfCycle(ListNode* head) {
    if (!head) return head;

    ListNode *slow, *fast;
    slow = fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) break;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);

    head.next->next->next->next = head.next;
    assert(startPointOfCycle(&head)->val == 2);
}