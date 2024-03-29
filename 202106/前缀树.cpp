class Trie {
private:
	vector<Trie*> children;
	bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() {
    	children.resize(26);
    	idEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	Trie* node = this;
    	for (char c : word) {
    		int i = c - 'a';
    		if (node->children[i] == nullptr) {
    			node->children[i] = new Trie();
    		}
    		node = node->children[i];
    	}
    	node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	Trie* node = this;
    	for (char c : word) {
    		int i = c - 'a';
    		if (node->children[i] == nullptr) {
    			return false;
    		}
    		node = node->children[i];
    	}
    	return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	Trie* node = this;
    	for (char c : word) {
    		int i = c - 'a';
    		if (node->children[i] == nullptr) {
    			return false;
    		}
    		node = node->children[i];
    	}
    	return true;
    }
};