/*
算法一：基本解法，只能被1和自己整除
*/

class Solution {
public:
    // 算法一、基本解法
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                res++;
            }
        }
        return res;
    }

    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    // 算法二、埃氏筛
    int countPrimes(int n) {
        int res = 0;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                res++;
                if ((long long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
                
            }
        }
        return res;
    }
};

