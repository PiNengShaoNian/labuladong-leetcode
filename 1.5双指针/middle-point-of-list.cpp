#include <cassert>
#include <vector>

#include "ListNode.h"

using namespace std;

ListNode* middlePointOfList(ListNode* head) {
    if (!head) return nullptr;
    ListNode *slow, *fast;
    slow = fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    vector<int> elems = {1, 2, 3, 4, 5, 6};
    vector<int> elems1 = {1, 2, 3, 4, 5};
    ListNode* head = buildLinkedList(elems);
    ListNode* head1 = buildLinkedList(elems1);

    assert(middlePointOfList(head)->val == 4);
    assert(middlePointOfList(head1)->val == 3);
}