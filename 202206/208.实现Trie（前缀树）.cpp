class Trie {
public:
    Trie() {
        this->end = false;
        this->children.resize(26); // 初始化26个空指针
    }
    
    void insert(string word) {
        Trie* p = this;
        for (char c: word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new Trie();
            }
            p = p->children[c - 'a'];
        }
        p->end = true;
    }
    
    bool search(string word) {
        Trie* p = this;
        for (char c: word) {
            if (!p->children[c - 'a']) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        return p->end;
    }
    
    bool startsWith(string prefix) {
        Trie* p = this;
        for (char c: prefix) {
            if (!p->children[c - 'a']) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        return true;
    }

public:
    vector<Trie*> children;
    bool end;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */