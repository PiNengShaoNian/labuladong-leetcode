#include <cassert>
#include <iostream>

#include "ListNode.h"

using namespace std;

bool hasCycle(ListNode *head) {
    ListNode *slow, *fast;
    slow = fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) return true;
    }

    return false;
}

int main() {
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);

    assert(hasCycle(&head) == false);

    head.next->next->next->next = &head;
    assert(hasCycle(&head) == true);
}