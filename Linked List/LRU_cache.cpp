// https://leetcode.com/problems/lru-cache/

class LRUCache {
private:
    int cap; // Capacity of the cache
    class Node{
    public:
        int key, val;
        Node *next, *prev;
        Node(){
            key = 0;
            val = 0;
            next = nullptr;
            prev = nullptr;
        }
        Node(int k, int v){
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node *left, *right;
    map<int, Node *> m;
public:
    LRUCache(int capacity) {
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
        cap = capacity;
    }
    
    // remove node from the list
    void remove(Node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    
    // insert at the right most pos in the list
    void insert(Node *n){
        right->prev->next = n;
        n->next = right;
        n->prev = right->prev;
        right->prev = n;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            remove(m[key]);
            insert(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            remove(m[key]);
        }
        m[key] = new Node(key, value);
        insert(m[key]);
        
        if(m.size() > cap){
            // remove the LRU value from cache (both list and map)
            Node *LRU = left->next;
            m.erase(LRU->key);
            remove(LRU);
            delete(LRU);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
