#include <cassert>
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head) {
    stack<ListNode *> nodes;

    for (ListNode *cur = head; cur; cur = cur->next) {
        nodes.push(cur);
    }

    ListNode *cur = head;
    while (!nodes.empty()) {
        if (nodes.top()->val != cur->val) return false;

        nodes.pop();
        cur = cur->next;
    }

    return true;
}

int main() {
    ListNode head1 = ListNode(1, new ListNode(2, new ListNode(1)));
    ListNode head2 = ListNode(1, new ListNode(2));
    ListNode head3 =
        ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    assert(isPalindrome(&head1) == true);
    assert(isPalindrome(&head2) == false);
    assert(isPalindrome(&head3) == true);

    return 0;
}
