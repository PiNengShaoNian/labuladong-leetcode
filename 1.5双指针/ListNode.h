#if !defined(LISTNODE_H)
#define LISTNODE_H

#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* buildLinkedList(std::vector<int>& elems) {
    if (!elems.size()) return nullptr;
    ListNode* head = new ListNode(elems[0]);
    ListNode* cur = head;
    for (int i = 1; i < elems.size(); ++i) {
        cur->next = new ListNode(elems[i]);
        cur = cur->next;
    }

    return head;
}

#endif  // LISTNODE_H
