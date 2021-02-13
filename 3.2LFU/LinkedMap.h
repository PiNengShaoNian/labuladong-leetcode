
#ifndef __LINKED_MAP_H__
#define __LINKED_MAP_H__

#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER > 1000

#pragma warning(disable : 4786)
#pragma warning(disable : 4503)

#include <assert.h>

#include <list>
#include <map>

class noncopyable {
   protected:
    noncopyable() {}
    ~noncopyable() {}

   private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};

// Note: assumes K and V are POD types.
template <typename K, typename V>
class Linked_map : private noncopyable {
   public:
    // The type of a value in the map.
    typedef std::pair<K, V> value_type;

    // The type of a non-const iterator over the map.
    typedef typename std::list<value_type>::iterator iterator;

    // The type of a const iterator over the map.
    typedef typename std::list<value_type>::const_iterator const_iterator;

    typedef typename std::map<K, iterator>::iterator pIterator;

    // Constructor.
    Linked_map() : sizes_(0) {}

    // Destructor.
    ~Linked_map() {}

    // Get an iterator for the beginning of the map.
    iterator begin() { return values_.begin(); }

    // Get an iterator for the beginning of the map.
    const_iterator begin() const { return values_.begin(); }

    // Get an iterator for the end of the map.
    iterator end() { return values_.end(); }

    // Get an iterator for the end of the map.
    const_iterator end() const { return values_.end(); }

    // Check whether the map is empty.
    bool empty() const { return values_.empty(); }

    // Find an entry in the map.
    iterator find(const K& k) {
        if (sizes_ > 0) {
            pIterator it = mappeds_.find(k);
            if (it == mappeds_.end()) return values_.end();
            iterator find_it = it->second;
            return find_it;
        }
        return values_.end();
    }

    // Find an entry in the map.
    const_iterator find(const K& k) const {
        if (sizes_ > 0) {
            pIterator it = mappeds_.find(k);
            if (it == mappeds_.end()) return values_.end();
            const_iterator find_it = it->second;
            return find_it;
        }
        return values_.end();
    }

    // Insert a new entry into the map.
    std::pair<iterator, bool> insert(const value_type& v) {
        pIterator pIt = mappeds_.find(v.first);
        if (pIt == mappeds_.end()) {
            values_.push_back(v);
            mappeds_.insert(std::pair<K, iterator>(v.first, --values_.end()));
            ++sizes_;
        } else {
            values_.erase(pIt->second);
            values_.push_back(v);
            pIt->second = --values_.end();
        }
        return std::pair<iterator, bool>(--values_.end(), true);
    }

    // Insert an element value to the list of the specified location.
    iterator insert(iterator it, const value_type& v) {
        pIterator pIt = mappeds_.find(v.first);
        if (pIt != mappeds_.end()) {
            values_.erase(pIt->second);
            --sizes_;
        }
        iterator _it = values_.insert(it, v);
        mappeds_.insert(std::pair<K, iterator>(v.first, _it));
        ++sizes_;
        return _it;
    }

    // Erase an entry from the map.
    void erase(iterator it) {
        assert(it != values_.end());
        assert(sizes_ != 0);

        value_type v = *it;
        values_.erase(it);
        mappeds_.erase(v.first);
        --sizes_;
    }

    // Erase a key from the map.
    void erase(const K& k) {
        iterator it = find(k);
        if (it != values_.end()) erase(it);
    }

    // Remove all entries from the map.
    void clear() {
        // Clear the values.
        values_.clear();
        mappeds_.clear();
        sizes_ = 0;
    }

    // Calculate the number of elements.
    size_t size() { return sizes_; }

   private:
    // The number of elements in the map.
    size_t sizes_;

    // The list of all values in the map.
    std::list<value_type> values_;

    // The map of list nodes.
    std::map<K, iterator> mappeds_;
};

#endif