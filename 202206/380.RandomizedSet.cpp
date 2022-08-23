/**
 * 算法：数组+哈希表
 * 思路：哈希表实现O(1)查找和删除，数组实现随机查找
 */

class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> vec;

public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            mp[val] = mp.size();
            vec.push_back(val);
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        vec[mp[val]] = vec.back(); // 交换位置
        mp[vec.back()] = mp[val]; // 交换位置
        vec.pop_back(); // 删除
        mp.erase(val); // 删除
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */