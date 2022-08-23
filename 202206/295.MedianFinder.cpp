/*
算法一：双优先队列，分别维护大于中位数的数，和小于等于中位数的数。
*/
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> q_min; // 小于等于中位数的数，大顶堆
    priority_queue<int, vector<int>, greater<int>> q_max; // 大于中位数的数，小顶堆

public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (q_min.empty() || num < q_min.top()) {
            q_min.emplace(num);
            if (q_min.size() > q_max.size() + 1) {
                q_max.push(q_min.top());
                q_min.pop();
            }
        } else {
            q_max.emplace(num);
            if (q_max.size() > q_min.size()) {
                q_min.push(q_max.top());
                q_max.pop();
            }
        }
    }
    
    double findMedian() {
        if (q_min.size() > q_max.size()) {
            return q_min.top();
        } else {
            return (q_min.top() + q_max.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * 算法二、有序集合+双指针
 * 有序集合实现O(logn)的排序效率，不过需要指针更新中位数的指针
 */

class MedianFinder {
public:
    multiset<int> nums; // 有序集合（可重复）
    multiset<int>::iterator left, right; // 双指针

public:
    MedianFinder() {
        left = nums.end();
        right = nums.end();
    }
    
    void addNum(int num) {
        const size_t n = nums.size();
        nums.insert(num);
        if (!n) { // 初始时
            left = right = nums.begin();
        } else if (n & 1) { // 插入前是奇数
            if (num < *left) {
                left--;
            } else { // 重复插入的数会放在后面
                right++;
            }
        } else { // 插入前是偶数
            if (num >= *left && num < *right) {
                left++;
                right--;
            } else if (num < *left) {
                right--;
            } else {
                left++;
            }
        }
    }
    
    double findMedian() {
        return (*left + *right) / 2.0;
    }
};