/*

Project - LRU Cache System
Name - Sompa Bhui
College - VIT Bhopal

Description:
This project implements an LRU (Least Recently Used) Cache System
commonly used in real-world software systems to reduce access latency
by evicting least recently accessed data when capacity is reached.

*/

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// LRU Cache System
// ----------------
// This cache system keeps the most recently accessed data readily available
// and evicts the least recently used data when the cache reaches its capacity.
// Internally, it uses:
// 1. Doubly Linked List -> to maintain usage order
// 2. Unordered Map -> for O(1) key-based access

class LRU_Cache {
public:
    // Doubly linked list stores cached values (most recent at front)
    list<string> cacheList;

    // Hash map maps keys to list iterators for O(1) access
    unordered_map<int, list<string>::iterator> cacheMap;

    // Maximum number of entries allowed in cache
    int capacity;

    // Constructor: initializes cache with fixed capacity
    LRU_Cache(int cap) {
        if (cap > 0) {
            capacity = cap;
        } else {
            cout << "ERROR: Cache capacity must be greater than 0" << endl;
            capacity = 0;
        }
        cacheList.clear();
        cacheMap.clear();
    }

    // Returns the configured cache capacity
    int size() {
        return capacity;
    }

    // Inserts or updates data in the cache
    void feedin(int key, string data) {

        // Case 1: Key not present in cache
        if (cacheMap.find(key) == cacheMap.end()) {

            // If cache is full, evict least recently used entry
            if (cacheList.size() == capacity) {

                // Identify the LRU element (last element in list)
                auto lruIterator = --cacheList.end();

                // Remove corresponding key from map
                for (auto it : cacheMap) {
                    if (it.second == lruIterator) {
                        cacheMap.erase(it.first);
                        break;
                    }
                }

                // Remove LRU value from cache list
                cacheList.pop_back();
            }

            // Insert new data at front (most recently used)
            cacheList.push_front(data);
            cacheMap[key] = cacheList.begin();
        }

        // Case 2: Key already present -> update and move to front
        else {
            cacheList.erase(cacheMap[key]);
            cacheList.push_front(data);
            cacheMap[key] = cacheList.begin();
        }
    }

    // Retrieves data for a given key
    string gettin(int key) {

        // Cache miss
        if (cacheMap.find(key) == cacheMap.end()) {
            return "0";
        }

        // Cache hit
        return *cacheMap[key];
    }
};

int main() {

    // Creating an LRU Cache System with capacity = 2
    LRU_Cache cache(2);

    cout << "Cache Capacity: " << cache.size() << endl;

    // Inserting data into cache
    cache.feedin(1, "beta");
    cache.feedin(3, "alpha");
    cache.feedin(8, "gamma"); // Evicts key 1 due to capacity limit

    // Accessing cache data
    cout << cache.gettin(1) << endl; // Cache miss
    cout << cache.gettin(3) << endl; // Cache hit
    cout << cache.gettin(6) << endl; // Cache miss
    cout << cache.gettin(8) << endl; // Cache hit

    return 0;
}
