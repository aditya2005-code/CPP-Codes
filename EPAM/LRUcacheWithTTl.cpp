#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int value;
    long long expiryTime;

    Node(int key, int value, long long expiryTime) {
        this->key = key;
        this->value = value;
        this->expiryTime = expiryTime;
    }
};

class LRU {
private:
    int capacity;

    // Front = Most Recently Used
    // Back = Least Recently Used
    list<Node> dll;

    // key -> iterator pointing to its node in the list
    unordered_map<int, list<Node>::iterator> present;

    long long getCurrentTime() {
        return chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch()
        ).count();
    }

public:
    LRU(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        // Key does not exist
        if (present.count(key) == 0) {
            return -1;
        }

        auto it = present[key];

        // Check if expired
        if (getCurrentTime() >= it->expiryTime) {
            dll.erase(it);
            present.erase(key);
            return -1;
        }

        // Move accessed node to front (MRU)
        dll.splice(dll.begin(), dll, it);

        return dll.begin()->value;
    }

    void put(int key, int value, long long ttl) {

        long long expiryTime = getCurrentTime() + ttl;

        // If key already exists, update it
        if (present.count(key)) {
            auto it = present[key];

            it->value = value;
            it->expiryTime = expiryTime;

            // Move updated node to front
            dll.splice(dll.begin(), dll, it);
            return;
        }

        // If cache is full, remove LRU element
        if (dll.size() >= capacity) {
            int lruKey = dll.back().key;

            present.erase(lruKey);
            dll.pop_back();
        }

        // Insert new element at front
        dll.push_front(Node(key, value, expiryTime));

        // Store iterator in hashmap
        present[key] = dll.begin();
    }

    void display() {
        cout << "Cache: ";

        for (auto node : dll) {
            cout << "[" << node.key << ":" << node.value << "] ";
        }

        cout << endl;
    }
};

int main() {

    LRU cache(2);

    // ttl is in milliseconds

    cache.put(1, 100, 5000);
    cache.put(2, 200, 5000);

    cache.display();

    cout << "get(1): " << cache.get(1) << endl;

    // Key 1 becomes most recently used
    cache.display();

    // Cache capacity is 2
    // Key 2 is LRU, so it will be removed
    cache.put(3, 300, 5000);

    cache.display();

    cout << "get(2): " << cache.get(2) << endl;
    cout << "get(1): " << cache.get(1) << endl;
    cout << "get(3): " << cache.get(3) << endl;

    return 0;
}