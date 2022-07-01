// https://leetcode.com/problems/implement-trie-prefix-tree/submissions/

class TrieNode {
public:
    vector<TrieNode *> v;
    bool endOfWord;
    TrieNode(): v(26, nullptr), endOfWord(false) {}
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(char& c: word){
            if(!curr->v[c-'a'])
                curr->v[c-'a'] = new TrieNode();
            curr = curr->v[c-'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char& c: word){
            if(!curr->v[c-'a'])
                return false;
            curr = curr->v[c-'a'];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char& c: prefix){
            if(!curr->v[c-'a'])
                return false;
            curr = curr->v[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */