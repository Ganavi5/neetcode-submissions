#include <unordered_map>

class LRUCache {
private:
    // Doubly Linked List Node structure
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache; // Maps key -> Node pointer
    
    // Sentinel dummy nodes to eliminate boundary/null pointer edge cases
    Node* head;
    Node* tail;

    // Remove a node from its current position in the list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert a node immediately after dummy head (Most Recently Used position)
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Move an existing node to the MRU position
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    // Remove and delete the least recently used node (node right before dummy tail)
    Node* removeTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Destructor to clean up allocated node memory
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1; // Key does not exist
        }
        
        Node* node = it->second;
        moveToHead(node); // Accessing key promotes it to MRU
        return node->value;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            // Key exists: update value and promote to MRU
            Node* node = it->second;
            node->value = value;
            moveToHead(node);
        } else {
            // Key does not exist: check for capacity overload
            if (cache.size() >= capacity) {
                Node* lru = removeTail();
                cache.erase(lru->key); // Evict from hash map
                delete lru;            // Free memory
            }

            // Create new node and add to cache
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
        }
    }
};