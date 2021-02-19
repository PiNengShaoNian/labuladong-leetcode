#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* successor;
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
        successor = head->next;
        return head;
    }

    ListNode* last = reverseN(head->next, n - 1);

    head->next->next = head;
    head->next = successor;

    return last;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == 1) {
        return reverseN(head, n);
    }

    head->next = reverseBetween(head->next, m - 1, n - 1);

    return head;
}

int main() {
    ListNode head(
        1, new ListNode(
               2, new ListNode(
                      3, new ListNode(4, new ListNode(5, new ListNode(6))))));

    ListNode* newHead = reverseN(&head, 3);

    assert(newHead->val == 3);
    assert(newHead->next->val == 2);
    assert(newHead->next->next->val == 1);
    assert(newHead->next->next->next->val == 4);
    assert(newHead->next->next->next->next->val == 5);
}