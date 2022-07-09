struct DLinkNode {
	DLinkNode() : key(0), val(0), pre(nullptr), next(nullptr) {}
	DLinkNode(int key, int val) : key(key), val(val), pre(pre), next(next) {}
	int val;
	DLinkNode* pre;
	DLinkNode* next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
    	capacity = capacity;
    	head = new DLinkNode();
    	tail = new DLinkNode();
    	head->next = tail;
    	tail->pre = head;
    }
    
    int get(int key) {
    	if (hash_table.find(key) != hash_table.end()) {
    		DLinkNode* node = hash_table[key];
    		moveToHead(node);
    		return node->val;
    	} else {
    		return -1;
    	}
    }
    
    void put(int key, int value) {
    	if (hash_table.find(key) != hash_table.end()) {
    		DLinkNode* node = hash_table[key];
    		node->val = value;
    		moveToHead(node);
    	} else if (hash_table.size() == capacity) {
    		removeTail();
    		hash_table.erase(tail->pre->key);
    		DLinkNode* node = new DLinkNode(value);
    		hash_table[key] = node;
    		addToHead(node);
    	} else {
    		DLinkNode* node = new DLinkNode(value);
    		hash_table[key] = node;
    		addToHead(node);
    	}
    }

    void addToHead(DLinkNode* node) {
    	node->next = head->next;
    	head->next->pre = node;
    	head->next = node;
    	node->pre = head;
    }

    void removeTail() {
    	deleteNode(tail->pre);
    }

    void deleteNode(DLinkNode* node) {
    	node->pre->next = node->next;
    	node->next->pre = node->pre;
    }

    void moveToHead(node) {
    	deleteNode(node);
    	addToHead(node);
    }
private:
	int capacity;
	map<int, DLinkNode*> hash_table;
	DLinkNode* head;
	DLinkNode* tail;
};	