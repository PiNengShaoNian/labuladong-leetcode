#ifndef CHAPTER3_2_LFU
#define CHAPTER3_2_LFU

#include <unordered_map>

#include "LinkedMap.h"

template <typename Key, typename Value>
class LFU {
   private:
    /* data */
    std::unordered_map<Key, Value> keyToVal;
    std::unordered_map<Key, int> keyToFreq;
    std::unordered_map<int, Linked_map<Key, bool>> freqToKeys;
    size_t _capacity;
    int minFreq;

    void increaseFreq(const Key& key) {
        int freq = keyToFreq.find(key)->second;

        ++keyToFreq[key];

        freqToKeys[freq + 1].insert(
            std::make_pair<const Key&, bool>(key, true));
        freqToKeys[freq].erase(key);
        if (freqToKeys[freq].size() == 0) {
            freqToKeys.erase(freq);
            if (freq == minFreq) ++minFreq;
        }
    }

    void removeMinFreq() {
        auto deleteKey = freqToKeys[minFreq].begin();

        freqToKeys[minFreq].erase(deleteKey);
        if (freqToKeys[minFreq].size() == 0) {
            freqToKeys.erase(minFreq);
        }

        keyToVal.erase(deleteKey->first);
        keyToFreq.erase(deleteKey->first);
    }

   public:
    LFU(size_t capacity);
    ~LFU();

    void put(const Key& key, const Value& value) {
        if (_capacity <= 0) return;

        auto it = keyToVal.find(key);

        if (it != keyToVal.cend()) {
            keyToVal[key] = value;
            increaseFreq(key);

            return;
        }

        if (_capacity <= keyToVal.size()) {
            removeMinFreq();
        }

        keyToVal[key] = value;
        keyToFreq[key] = 1;
        /*if (freqToKeys.find(1) == freqToKeys.cend()) {
                Linked_map<Key, bool> list;
                freqToKeys.insert(
                        std::make_pair<int, Linked_map<Key, bool>&>(1, list));
        }*/

        freqToKeys[1].insert({key, true});
        minFreq = 1;
    }

    Value* get(const Key& key) {
        auto it = keyToVal.find(key);

        if (it == keyToVal.cend()) return nullptr;

        increaseFreq(key);

        return new Value(it->second);
    }

    size_t size() { return keyToVal.size(); }
};

template <typename Key, typename Value>
LFU<Key, Value>::LFU(size_t capacity) : _capacity(capacity) {}

template <typename Key, typename Value>
LFU<Key, Value>::~LFU() {}

#endif