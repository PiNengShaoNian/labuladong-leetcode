#include <cassert>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* l, ListNode* r) {
    ListNode *prev = nullptr, *cur, *next;

    cur = l;
    while (cur != r) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *l, *r;
    l = r = head;
    for (int i = 0; i < k; ++i) {
        if (!r) return head;
        r = r->next;
    }

    ListNode* newHead = reverse(l, r);

    l->next = reverseKGroup(r, k);

    return newHead;
}

int main() {
    ListNode head(
        1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    ListNode* newHead = reverseKGroup(&head, 2);

    assert(newHead->val == 2);
    assert(newHead->next->val == 1);
    assert(newHead->next->next->val == 4);
    assert(newHead->next->next->next->val == 3);
    assert(newHead->next->next->next->next->val == 5);

    return 0;
}