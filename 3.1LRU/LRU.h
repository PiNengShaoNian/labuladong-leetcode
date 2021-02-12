#ifndef CHAPTER3_1_LRU
#define CHAPTER3_1_LRU

#include <unordered_map>

template <typename Key, typename Value>
class Cache {
   private:
    /* data */
    struct ListNode {
        ListNode* prev;
        ListNode* next;
        Key key;
        Value value;

        ListNode(Key k, Value v)
            : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    ListNode* listHead;
    ListNode* listTail;
    std::unordered_map<Key, ListNode*> map;
    int maxCacheSize;

    void removeNodeFromList(ListNode* node) {
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        if (node == listHead) listHead = node->next;
        if (node == listTail) listTail = node->prev;
    }

    void insertAtFrontOfList(ListNode* node) {
        if (!listHead) {
            listHead = listTail = node;
            return;
        }

        node->next = listHead;
        listHead->prev = node;
        listHead = node;
    }

   public:
    Cache(int maxCacheSize);
    ~Cache();

    void remove(const Key& key) {
        auto it = map.find(key);
        if (it == map.cend()) return;

        this->removeNodeFromList(it->second);
        map.erase(key);
    }

    void set(const Key& key, const Value& value) {
        remove(key);

        if (map.size() == maxCacheSize && listTail) {
            remove(listTail->key);
        }

        ListNode* node = new ListNode(key, value);
        insertAtFrontOfList(node);
        map[key] = node;
    }

    Value* get(const Key& key) {
        auto it = map.find(key);
        if (it == map.cend()) return nullptr;

        ListNode* node = it->second;
        if (node != listHead) {
            removeNodeFromList(node);
            insertAtFrontOfList(node);
        }

        Value* value = new Value(node->value);
        return value;
    }

    auto size() { return map.size(); }
};

template <typename Key, typename Value>
Cache<Key, Value>::Cache(const int maxSize)
    : listHead(nullptr), listTail(nullptr), maxCacheSize(maxSize) {}

template <typename Key, typename Value>
Cache<Key, Value>::~Cache() {
    ListNode* head = listHead;

    while (head) {
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }
}

#endif