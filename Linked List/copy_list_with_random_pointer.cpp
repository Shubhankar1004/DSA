// https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node *, Node *> oldToCopy;
        Node *p = head, *copy = nullptr, *q, *prev = nullptr;
        
        // create copy list
        int l = 1;
        while(p != nullptr){
            q = new Node(p->val);
            oldToCopy[p] = q; // use hashmap to store links from old node to corresponding copy
            if(copy == nullptr)
                copy = q;
            if(prev != nullptr)
                prev->next = q;
            prev = q;
            p = p->next;
        }
        
        // assign the random pointers in the new list
        Node *p1 = head, *p2 = copy;
        while(p1 != nullptr){
            q = p1->random;
            if(q == nullptr)
                p2->random = nullptr;
            else
                p2->random = oldToCopy[q];
            p1 = p1->next;
            p2 = p2->next;
        }
        return copy;
    }
};
