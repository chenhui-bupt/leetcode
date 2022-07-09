class Solution {
public:

	vector<Trie*> children;
	bool isEnd;

	Trie() {
		children.resize(26, nullptr);
		isEnd = false;
	}

	void insert(string& s) {
		Trie* node = this;
		for (char c: s) {
			if (!node->children[c - 'a']) {
				node->children[c - 'a'] = new Trie();
			}
		}
		node->isEnd = true;
	}

	bool search(strings s) {
		Trie* node = this;
		for (char c: s) {
			if (!node->children[c - 'a']) {
				return false;
			} else {
				node = node->children[c - 'a'];
			}
		}
		return node->isEnd;
	}

	bool startswith(string& s) {
		Trie* node = this;
		for (char c: s) {
			if (node->children[c - 'a']) {
				node = node->children[c - 'a'];
			} else {
				return false;
			}
		}
		return true;
	}
}