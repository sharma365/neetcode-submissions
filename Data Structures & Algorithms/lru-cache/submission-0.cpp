#include <unordered_map>

class LRUCache {
private:
    // Define the Doubly Linked List Node structure
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cacheMap;
    
    // Dummy head and tail nodes to avoid edge-case pointer checks
    Node* head;
    Node* tail;

    // Helper: Adds a node immediately after the dummy head (Most Recently Used position)
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper: Breaks standard links to cleanly remove a node from its current spot
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: Refreshes a node's usage by moving it to the front
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // Initialize dummy head and tail bound together
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    // Destructor to clean up memory dynamically allocated for nodes
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1;
        }
        
        Node* node = it->second;
        moveToHead(node); // Move to front since it was just accessed
        return node->val;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        
        if (it != cacheMap.end()) {
            // Key exists: Update its value and bump to the front
            Node* node = it->second;
            node->val = value;
            moveToHead(node);
        } else {
            // Key does not exist: Evict if capacity is reached
            if (cacheMap.size() == capacity) {
                Node* lruNode = tail->prev; // Node right before dummy tail is the oldest
                cacheMap.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode; // Free memory
            }
            
            // Create and insert the new node
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            addNode(newNode);
        }
    }
};
