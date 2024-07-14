/*
算法一：双优先队列，分别维护大于中位数的数，和小于及等于中位数的数。
思路一：
1、大顶堆负责维护小于及等于中位数的数，小顶堆负责维护大于中位数的数；
2、同时注意交换两个堆堆顶的元素，使得两个堆的元素个数平衡；
3、中位数即是大顶堆的堆顶元素（奇数时），或者两个堆顶元素的均值（偶数时）
*/
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> q_min; // 小于及等于中位数的数，大顶堆
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
 * 思路二：有序集合multiset负责维护数据流元素的顺序，左右指针实时调整指向中位数（奇数时两指针相等，偶数时两指针相邻）
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
        } else if (n & 1) { // 插入前是奇数（左右指针相等）
            if (num < *left) { // 插入的数小于左指针时，向左移动左指针
                left--;
            } else { // 插入的数大于等于左指针时（重复的数会放在后面），向右移动右指针
                right++;
            }
        } else { // 插入前是偶数（左右指针相邻）
            if (num >= *left && num < *right) { // 插入的数在中间，因此左右指针相向移动
                left++;
                right--;
            } else if (num < *left) { // 插入的数小于左指针，右指针向左移动（与左指针相等）
                right--;
            } else { // 插入的数大于等于右指针，左指针右移（与右指针相等）
                left++;
            }
        }
    }
    
    double findMedian() {
        return (*left + *right) / 2.0;
    }
};