#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int cap;
    // Stores {key, value} pairs, most recent at the front
    list<pair<int, int>> cache;
    // Maps key to iterator of the corresponding list node
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        // Move accessed node to the front (most recent)
        cache.splice(cache.begin(), cache, m[key]);
        return m[key]->second;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Update existing value and move to front
            m[key]->second = value;
            cache.splice(cache.begin(), cache, m[key]);
            return;
        }

        // Evict least recent if at capacity
        if (cache.size() == cap) {
            m.erase(cache.back().first);
            cache.pop_back();
        }

        // Insert new pair at the front
        cache.emplace_front(key, value);
        m[key] = cache.begin();
    }
};