#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   private:
    bool type;
    vector<NestedInteger> list;
    int num;

   public:
    // Return true if this NestedInteger holds a single integer, rather thana
    // nested list.

    NestedInteger(bool t, vector<NestedInteger> &&list, int num)
        : list(list), num(num), type(t) {}

    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;

    void push(const NestedInteger &nested) { list.push_back(nested); }
};

bool NestedInteger::isInteger() const { return type == 1; }

int NestedInteger::getInteger() const { return num; }

const vector<NestedInteger> &NestedInteger::getList() const { return list; }

class NestedIterator {
   private:
    bool isEmpty() const { return !data.size() && !buffer.size(); }
    deque<NestedInteger> data;
    deque<int> buffer;
    void flatten(const NestedInteger &item) {
        if (item.isInteger())
            buffer.push_back(item.getInteger());
        else {
            for (const NestedInteger &nested : item.getList()) {
                flatten(nested);
            }
        }
    }

   public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        data = deque<NestedInteger>(nestedList.begin(), nestedList.end());
    }

    int next() {
        if (!buffer.size()) {
            NestedInteger item = data.front();
            data.pop_front();
            flatten(item);
        }

        int result = buffer.front();
        buffer.pop_front();
        return result;
    }

    bool hasNext() { return !isEmpty(); }
};

int main() {
    //[1,[4,[6]]]

    vector<NestedInteger> vec;

    vec.emplace_back(1, vector<NestedInteger>(), 1);

    NestedInteger n1(0, vector<NestedInteger>(), -1);

    NestedInteger n2(1, vector<NestedInteger>(), 4);
    n1.push(n2);

    NestedInteger n3(0, vector<NestedInteger>(), -1);
    NestedInteger n4(1, vector<NestedInteger>(), 6);
    n3.push(n4);

    n1.push(n3);

    vec.push_back(n1);

    NestedIterator it(vec);

    cout << it.next() << endl;
    cout << it.next() << endl;
    cout << it.next() << endl;
}