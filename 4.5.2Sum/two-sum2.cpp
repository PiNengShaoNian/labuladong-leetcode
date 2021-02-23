#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

class TwoSum {
   private:
    unordered_map<int, int> freq;

   public:
    void add(int num) { ++freq[num]; }

    bool find(int value) {
        for (auto it : freq) {
            int num, freqOfNum;

            num = it.first;
            freqOfNum = it.second;

            if (value - num == num && freqOfNum > 1) return true;

            if (value - num != num && freq.find(value - num) != freq.cend())
                return true;
        }

        return false;
    }
};

int main() {
    TwoSum ts;

    assert(ts.find(1) == false);

    ts.add(1);
    ts.add(0);
    assert(ts.find(1) == true);

    ts.add(4);
    assert(ts.find(8) == false);
    ts.add(4);
    assert(ts.find(8) == true);

    return 0;
}