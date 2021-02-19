#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* last = reverse(head->next);

    head->next->next = head;
    head->next = nullptr;

    return last;
}

int main() {
    ListNode head(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    ListNode* newHead = reverse(&head);

    assert(newHead->val == 4);
    assert(newHead->next->val == 3);
    assert(newHead->next->next->val == 2);
    assert(newHead->next->next->next->val == 1);
}
