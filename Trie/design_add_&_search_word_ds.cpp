// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class Node{
public:
    Node *v[26];
    bool isEnd;
    Node(): isEnd(false) {
        for(int i=0; i<26; i++)
            v[i] = nullptr;
    }
};

class WordDictionary {
    Node *root;
    bool dfs(int j, Node *root, string& word){
        Node *curr = root;
        for(int i=j; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                // go over the children
                for(int j=0; j<26; j++){
                    if(curr->v[j]){
                        if (dfs(i+1, curr->v[j], word))
                            return true;
                    }
                    else
                        continue;
                }
                return false;
            }
            else{
                if(!curr->v[c-'a'])
                    return false;
                curr = curr->v[c-'a'];
            }
        }
        return curr->isEnd;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *curr = root;
        for(char& c: word){
            if(!curr->v[c-'a'])
                curr->v[c-'a'] = new Node();
            curr = curr->v[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(0, root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
