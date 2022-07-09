class Trie {
public:
	Trie() {
		children.resize(26);
		isEnd = false;
	}

	void insert(string s) {
		Trie* node = this;
		for (char c: s) {
			if (!node->children[c - 'a']) {
				node->children[c - 'a'] = new Trie();
			}
			node = node->children[c - 'a'];
		}
		node->isEnd = true;
	}

	bool search(string& s) {
		Trie* node = this;
		for (char c : s) {
			if (node->children[c - 'a']) {
				node = node->children[c - 'a'];
			} else {
				return false;
			}
		}
		return node->isEnd;
	}

	bool startsWith(string& s) {
		Trie* node = this;
		for (char c : s) {
			if (node->children[c - 'a']) {
				node = node->children[c - 'a'];
			} else {
				return false;
			}
		}
		return true;
	}

private:
	vector<Trie*> children;
	bool isEnd;
};
