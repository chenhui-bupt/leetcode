/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

方法：借助数据结构
双向链表和哈希表
*/
struct DLinkNode {
    int key;
    int val;
    DLinkNode *pre;
    DLinkNode *next;
    DLinkNode() : key(0), val(0), pre(NULL), next(NULL) {}
    DLinkNode(int x, int y) : key(x), val(y), pre(NULL), next(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        moveToHead(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (mp.size() == _capacity) {
                removeTail();
                mp.erase(key);
            } 
            DLinkNode* node = new DLinkNode(key, value);
            addToHead(node);
        } else {
            mp[key]->val = value;
            moveToHead(mp[key]);
        }
    }

    void moveToHead(DLinkNode* node) {
        if (node == head->next) {
            return;
        }
        node->pre->next = node->next;
        node->next->pre = node->pre;
        addToHead(node);
    }

    void addToHead(DLinkNode* head) {
        node->pre = head;
        node->next = head->next;
        head->next = node;
    }

    void removeTail() {
        DLinkNode* node = tail->pre;
        node->pre->next = tail;
        tail->pre = node->pre;
        delete node;
    }

private:
    int _capacity;
    DLinkNode* head;
    DLinkNode* tail;
    unordered_map<int, DLinkNode*> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */