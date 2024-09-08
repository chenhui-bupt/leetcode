/*
动态规划
1、定义：
G[n]：序列长度为n的二叉搜索树的个数
F[i,n]：序列长度为n，根节点为i的二叉搜索树个数
2、递推关系式：
G[n] = sum(F[i, n])
F[i,n] = G[i-1] * G[n-i]
即，G[n] += G[i-1] * G[n-i]
3、初始化：
G[0] = 0;
G[1] = 1;

*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1);
        g[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                g[i] += g[j-1] * g[i-j];
            }
        }
        return g[n];
    }
};