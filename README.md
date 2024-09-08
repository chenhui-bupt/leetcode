1.两数和，twoSum
数据结构：哈希表
思路：空间换时间，哈希表存储过去遇到的数字，当遇到新数时，查看”差值“是否在哈希表中

拓展1：15.threeSum，三数和
思路：多一层循环先定一个数，将三数和问题转化成两数和，此时发现时间复杂度为O(n^2)
于是，直接先对数组预排序，然后定一个数，问题转化成有序数组的两数和，使用双指针查找即可，节省O(n)的哈希表存储空间。

其他拓展：组合总和；路径和

2.两数相加，addTwoNumbers
数据结构：链表
算法：迭代或递归
思路：链表相加，维护进位数即可

3.无重复字符最长子串，lengthOfLongestSubstring
数据结构：哈希表 + 单指针
思路：哈希表记录每个字符最新的位置，单指针负责计算无重复字符串的起点

4.排序数组的中位数，findMedianSortedArrays
数据结构：数组 + 单指针
算法：二分查找 + 递归
思路：本质是找第K大的数，使用累次剔除劣策略。因为在两个数组中找，因此需要每个数组先比较第k/2个，把无效的部分排除，最后到达边界时返回结果。边界条件：
（1）一个数组被完全排除，直接取第二个数组；
（2）k = 1，那就是两个数组中找最小的那个数

5.最长回文子串，longestPalindrom
数据结构：双指针
算法：中心展开法

8.字符串转数字，myAtoi
数据结构：字符串 + 哈希表
算法：有限状态机
思路：字符有四种状态”空格、符号、数字、其他“，构建状态转移表，表示各种状态之间的转移关系，相当于写了很多if else语句。当遇到新的字符时，根据上一个状态计算其转移状态，不同状态对应不同的动作，比如数字加和，符号识别，或者结束。

10.正则表达式匹配，isMatch
算法：递归dfs
'.' 匹配任意字符
'*' 匹配0次或1次（即多次）
边界条件：指针越界问题

11.盛水最多的容器，maxArea
数据结构：双指针
算法：累次剔除劣策略，比较两个指针的大小，删除无效解空间（对比暴力解法而言）

13.罗马数字转整数，romanToInt
数据结构：哈希表
算法：按照编码表规则实现即可

14.最长公共前缀
数据结构：字符串
算法：迭代遍历每个字符判定公共性，不是则返回结果

15.三数之和，threeSum
数据结构：哈希表，或，双指针
算法：预排序，定一个数字，将问题转化成两数之和

17.电话号码的字母组合，letterCombinations
数据结构：哈希表存储数字字母映射，队列queue
算法一：宽度优先遍历，数据结构：队列
算法二：深度优先遍历

19.删除链表的倒数第n个节点，removeNthFromEnd
数据结构：快慢指针
算法：构造哑结点，避免链表被完全删除，而找不到前后节点

20.有效括号数，isValid
数据结构：计数器，or，栈stack
算法：
算法1：通过左右括号计数器，当右括号数大于左括号数时，返回false，最后比较左右括号数是否相等
算法2：栈，通过栈维持左括号和匹配消除左括号，当遇到右括号，而栈空无法匹配时返回false，最后判定栈是否为空，即是否完全匹配。
扩展：22.括号生成

21.合并两个有序链表，MergeTwoLists
数据结构：双指针
算法：遍历

22.括号生成，generateParentheses
数据结构：计数器
算法：深度优先遍历dfs
思路：左右括号计数器，（1）当left < n时可以加左括号'('；（2）当right < left时，可以加右括号')'

23.合并K个升序链表，mergeKLists
数据结构：双指针
算法：二分归并（分治算法）
思路：先实现一个合并两个链表的算法，通过二分归并分治合并

24.两两交换链表中的节点
数据结构：链表
算法：递归 or 迭代
算法1：递归
思路1：
第一步：第二个节点作为新的头结点；
第二步：递归函数完成后面节点的交换；
第三步：第一个节点指向递归完成的节点，第二个节点指向第一个节点；


算法2：迭代
思路2：
第一步：构造一个哑结点，指向链表头结点；
第二步：双指针指向前两个节点，并完成交换；
第三步：移动指针；

25.K个一组翻转链表
数据结构：链表
算法：迭代
思路：
第一步：构造一个哑结点，指向链表头节点；
第二步：双指针指向第一个和第k个节点，若指针为空，则不用交换；不为空，完成这k个节点的链表逆序；
第三步：移动指针；

26.删除有序数组的重复项
数据结构：双指针
算法：迭代
思路：左指针指向最新的不重复的数字，右指针指向目前正在处理的数字

28.找出字符串中第一个匹配项的下标
数据结构：字符串
算法：KMP
思路：不会啊！

29.两数相除
算法：二分查找
思路：
第一步：将除数和被除数都转化成负数（负数表示的范围大，若是负数转换成正数，会出现溢出），商是正数；
第二步：在1和INT_MAX通过二分查找，找到商*除数最接近被除数的最大商；
第三步：再根据符号即是答案。

31.下一个排列，nextPermutation
数据结构：单调指针
算法：迭代
思路：用单调指针寻找待更新的数字，找到后与后面第一个刚好大于它的数互换，最后将后面的数字全部逆序，即是下一个排列（即一个位置进1，后续位置从小到大排列）

32.最长有效括号数，longestValidParentheses
数据结果：计数器 or 栈 or 数组
算法：
算法一：左右括号计数器
思路一：当右括号大于左括号时，计数器清零，当左右括号数相等时，记录有效括号长度

算法一：栈
思路二：维持括号的左边界，初始时放入-1，遇到右括号时匹配弹出栈顶左括号下标，同时记录有效括号数。
如果此时栈为空，就把下标i入栈表示新的左边界。

算法三：动态规划
思路三：左括号时dp[i] = 0，右括号时需要判定是否有左括号与之相匹配，同时加上匹配左括号前面已经匹配了的括号。
dp[i] = (i - dp[i - 1] - 2 >= 0) ? (dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]) : (dp[i - 1] + 2);

33.搜索旋转排序数组，search
数据结构：数组
算法：二分法，在连续的空间里进行二分查找

34.在排序数组中查找元素的第一个和最后一个位置，searchRange
数据结构：
算法：二分法，第一个mid =（left+right) >> 1，最后一个mid =（left+right+1)>>1;

36.有效数独
数据结构：哈希表（容器vector）
算法：哈希表计数器
思路：遍历二维数独矩阵，统计所在行、列、3*3区域内数字的个数；判断数字的个数是否重复，
若重复直接返回false。

38.外观数列
算法：递归，深度优先遍历

39.组合总和，combinationSum
数据结构：数组
算法：深度优先遍历
思路：每次选择或不选择，当index = size时判断tsum是否等于target，放入结果集中

41.缺失的第一个正数
数据结构：数组（类哈希表）
算法一：数组标记法
思路：确定值域在[1, n+1]范围内，遍历数组，并将其对应位置的下标置为负数，然后再次遍历遇到第一个正数的下标即是答案。

算法二：置换法
思路二：确定值域在[1, n+1]范围内，遍历数组，并将其置换到正确的位置上，然后再次遍历遇到第一个位置不正确的下标即是答案。

42.接雨水，trap
数据结构一：单调递减栈
算法一：单调栈
思路一：单调递减栈维持洼地的左边界，遇到右边界时记录洼地的”底“，然后弹出左边界，计算面积

算法二：动态规划
思路二：计算左右两边的高峰，然后计算当前位置”洼柱“的面积

045.跳跃游戏2
算法一：动态规划
思路一：dp[i]表示跳到i处最小步数，遍历j∈[0, i-1]，找到跳到i处最小步数

算法二：贪心算法
思路二：因为最小步数step也是几个跳跃区间的叠加，所以跳跃过程肯定要经过step个区间的边界，那如何更新边界值，当前进指针i走到一个边界margin时，记录step++，并更新margin为当前跳跃最远距离jumpMost

46.全排列，permute
数据结构：状态数组
算法：深度优先遍历
思路：维持一个数字被选择的状态表，递归选择其中一个数字，当选择结束时放入结果集中

48.旋转图像，rotate
数据结构：二维数组
算法：先对角翻转，再水平翻转，即等效于顺时针旋转

49.字母异位词分组，groupAnagrams
数据结构：哈希表
算法：将每个字母异位词排序或某种哈希，即可进行分组

50.幂运算，Pow
算法一：快速幂 + 递归
思路一：将幂指数转换成正数，然后计算子问题：计算幂的根方解，则其解为子问题的”平方“。

算法二：快速幂 + 迭代
思路二：将上述递归步骤转换成迭代运算。

53.最大子数组和，maxSubArray
数据结构：数组
算法：动态规划
思路：记录当前位置最大和，当前一个位置和小于0，重新计数，即dp[i] = nums[i]

54.螺旋矩阵
数据结构：二维矩阵
算法：四指针法
思路：用上下左右四个指针不断更新边界，然后绕着边界逆时针取数，直到到达边界退出。

55.跳跃游戏，canJump
数据结构：数组
算法：动态规划
思路：记录每个位置能跳跃的最远距离，并且记录全局能跳跃的最远距离，当最远距离到达n-1时，直接返回true，当最远距离还达不到当前位置则返回false

56.合并区间，merge
数据结构：二维数组
算法：迭代
思路：先对二维数组按区间左边界进行预排序，遍历，当左边界大于结果集最后一个区间的右边界时，放入新的结果，否则更新最后一个区间的右边界

62.不同路径，uniquePaths
数据结构：二维数组
算法：动态规划，转移方程dp[i][j] = dp[i-1][j] + dp[i][j-1]

64.最小路径和，minPathSum
数据结构：二维数组
算法：动态规划
思路：每次选择最小的路径，等价于结果最小的路径

66.加一，plusOne
数据结构：数组
算法：进位标志法carry

69.平方根，mySqrt
算法一：对数函数求解法
思路一：平方根转换成对数函数形式

算法二：二分查找
思路二：二分查找，找到mid ^ 2 <= x的最大数（类似查找有序数组中目标值的左右边界）

算法三：牛顿迭代法
思路三：泰勒展开，求迭代公式x1 = x0 - f(x0) / f'(x0)

70.爬楼梯，climbStairs
数据结构：f1,f2
算法：动态规划
思路：斐波那契数列

72.编辑距离，minDistance
数据结构：数组
算法：动态规划
思路：增、删、改，三种编辑可能

73.矩阵置零
数据结构：二维数组
算法：自身标记法
思路：利用第0行和第0列标记需要置0的行列，然后从m-1行倒着往0行处理置零。同时需要增加一个单独标记第0列是否需要置零的标记。

75.颜色分类，sortColors
数据结构：双指针
算法：双指针，先排2，再排0

76.最小覆盖子串，minWindow
数据结构：哈希表，双指针
算法：在匹配的情况下，逐步右移左边界，寻找更小的覆盖区间

78.子集，subsets
数据结构一：队列queue
算法一：宽度优先算法
思路一：一层一层的处理

算法二：深度优先遍历
思路二：选或者不选，当i = size时放入结果集（注意与全排列的不同之处）

79.单词搜索，exist
数据结构：二维数组状态表
算法：深度优先遍历dfs
思路：从一个位置为起点深度遍历，不得重复遍历（设置状态位）

080.删除有序数组中的重复项2
数据结构：数组
算法：快慢指针
思路：快指针负责遍历，慢指针指向重复项不超过两次的最新位置

[重点]
84.柱状图中最大的矩形，largestRectangleArea
数据结构：单调递增栈 + 数组
算法：单调递增栈计算柱子i的“左右边界”！
思路：
第一步：单调递增栈从左到右计算左边界；
第二步：单调递增栈从右到左计算右边界
第三步：根据左右边界计算矩形面积

85.最大矩形，maximumRectangle
数据结构：单调递增栈 + 数组
算法：将问题转化成“84题柱状图中最大的矩形”，使用单调递增栈计算柱子j的“左右边界”
思路：
第一步：计算（0至i行)柱子的高度，得heights数组
第二步：单调递增栈从左到右，计算柱子j的左边界
第三步：单调递增栈从右到左，计算柱子j的右边界
第四步：计算柱子j的为高度的矩形面积
第五步：处理第i+1行。

88.合并两个有序数组
题目要求：合并两个有序数组，并放置在数组1中（数组1能容纳数组1和2）
算法：双指针法
思路：为了充分利用数组1的末尾空余空间，优先处理数组1和2中的最大数，利用双指针将
最大数放置的数组末尾，这样数组1中未处理过的元素不会被干扰

91.解码方法，numDecodings
数据结构：数组
算法：动态规划
思路：
第一步：构造解码表
第二步：初始化dp数组，遍历解码表，若当前编码存在于编码字符串中，则更新当前位置i的解码数量，dp[i] += dp[j]
第三步：返回最终整个字符串能解码的个数dp[n]

94.二叉树中序遍历，inorderTraversal
数据结构：栈 or 单指针
算法：迭代法 or 深度优先遍历 or 前一个指针迭代法
思路：
方法一：用栈维持二叉树节点的前后顺序，迭代遍历
方法二：用dfs算法按序递归调用
方法三：用前一个指针

96.不同的二叉搜索树，numTrees
数据结构：数组
算法：动态规划
思路：根据二叉搜索树的特性，将问题拆分成子问题处理，即G[n] = sum(F(i, n))

98.验证二叉搜索树，isValidBST
数据结构：栈
算法一：迭代法
思路一：迭代法，二叉树的中序遍历，比较节点是否递增

算法二：深度优先遍历
思路二：递归调用时通过父亲节点更新孩子节点的左右边界，判断是否合法

101.对称二叉树，isSymmetric
数据结构一：队列
算法一：宽度优先遍历
思路一：每次将左右子树压入队列，每次弹出两个节点进行比较

算法二：深度优先遍历
思路二：递归调用比较左右子树是否相等。

102.二叉树的层序遍历，levelOrder
数据结构：队列
算法：宽度优先遍历

103.二叉树之字型遍历，zigzagLevelOrder
数据结构：队列
算法：宽度优先遍历
思路：同102题层序遍历，只不过偶数层需要逆序遍历

104.二叉树的最大深度，maxDepth
数据结构：队列 or 递归调用栈
算法：宽度优先遍历 or 深度优先遍历
思路1：bfs，层序遍历
思路2：dfs，递归调用

105.从前序遍历和中序遍历中构建二叉树，buildTree
数据结构：数组，二叉树
算法：递归
思路：从前序遍历确定根节点，再从中序遍历中确定左右子树

108.有序数组转平衡二叉搜索树，sortedArrayToBST
算法：深度优先遍历
思路：二分构造根节点，递归构造左右子树，返回根节点

114.二叉树展开为链表，flatten
数据结构：二叉树
算法：二叉树的前一个节点
思路：利用二叉树的前一个节点将二叉树转变成链表

116.填充每个节点的下一个右侧节点指针
数据结构：队列
算法：宽度优先搜索
思路：通过层序遍历，建立水平方向上的右侧节点指针

118.杨辉三角，generate
数据结构：数组
算法：迭代
思路：因为杨辉三角每一层的数字只依赖于上一层的数字，因此可以通过迭代实现。

121.买卖股票的最佳时机，maxProfit
数据结构：数组
算法：动态规划
思路：在最便宜的时候买，之后在最贵的时候卖
tips：只买卖一次

122.买卖股票的最佳时机2，maxProfit
数据结构：数组
算法一：动态规划
思路一：股民只有两种状态：持有股票或持有现金，可以通过动态规划，记录每个时刻持有股票或持有现金的最大收益，最后时刻手中拥有的现金就是最大收益

算法二：贪心算法
思路二：进一步把股价趋势图画出来，可以看到，股民只要在每一次涨价都卖出股票，那它的收益肯定是最大化的，即res += (prices[i] - prices[i-1])
tips：可多次买卖

124.二叉树最大路径和，maxPathSum
数据结构：调用栈
算法：深度优先遍历
思路：返回左右子树和的最大值，供上层节点使用

125.是否是回文串，isPalindrom
数据结构：双指针
算法：中心反向而行

127.单词接龙，ladderLength
数据结构一：图 + 队列
算法一：宽度优先搜索
思路一：通过优化建图，引入“词根”减少建图的时间复杂度，然后利用”队列“进行宽度优先遍历算法，计算路径长度。

数据结构二：数组
算法二：动态规划
思路二：
第一步：初始时将beginWord转移而来的单词路径记作1
第二步：通过计算单词i从单词j转移而来的最短路径
第三步：最终找寻endWord的最短路径。

128.最长连续序列，longestConsecutive
数据结构：哈希表 or 左右子树法
算法一：哈希表
思路一：第一遍构造哈希表，第二遍判断是否为起点，然后自增遍历，找寻最长连续序列

算法二：哈希表左右子树法
思路二：类比二叉树路径和，计算和更新左右子树连续序列长度

130.被围绕的区域，solve
数据结构：二维数组
算法：深度优先遍历 or 宽度优先遍历
思路：先用深度优先遍历，把跟边界联通的’O‘标记成’A'，然后，把'O'改为'X'

131.分割回文子串，partition
数据结构：数组
算法：深度优先遍历
思路：通过指针和数组，不断地分割字符串，判定分割后的子串是否是回文串，并递归处理，最后将结果返回

134.加油站
算法一：动态规划
思路一：动态规划：dp记录当前剩余油量，负数时重新记录起始位置和油量，当再次走到起始位置时，判定油量情况，返回结果

算法二：贪心算法
思路二：贪心：能通过加油站，肯定要求：
（1）总的净油量为正，可以不断累加净值最后判定；
（2）每时每刻的净油量为正，那就要求起始位置从总净油量最少的地方开始也能走完。于是得解。

135.分发糖果
数据结构：数组
算法：哨兵算法
思路：第一步：从左到右遍历，当nums[i]大于nums[i-1]时，left[i] = left[i-1] + 1多分一个糖果，否则left[i] = 1只分一个糖果；
第二步：从右到左遍历，当nums[i]大于nums[i+1]时，right[i] = right[i+1] + 1多分一个糖果，否则right[i] = 1只分一个糖果；
第三步：从左到右遍历，第i个小朋友分到的糖果是左边和右边的最大值，即res[i] = max(left[i], right[i])

136.只出现一次的数字，singleNumber
数据结构：
算法：异或

138.复制带随机指针的链表
数据结构：链表 + 哈希表
算法：哈希表存储新旧链表对应节点的映射关系，便于复制随机指针

139.单词拆分，wordBreak
数据结构：哈希表
算法：动态规划
思路：将问题拆解成子问题优化，判断最后一个”单词“在不在词典中，如果在，问题就变成，上一个单词在不在词典中了

140.单次拆分2
数据结构：哈希表
算法：动态规划 or 递归
思路：类比139题，将单词表存储哈希表中，对单词进行拆分判定是否在哈希表中，如果在就拼接新的单词到末尾。当然这一过程也可以用递归。

141.环形链表，hasCycle
数据结构：快慢指针
算法：快慢指针法
思路：快慢指针是否相交，相交后两指针位置距离正好等于链表环的长度，将慢指针从头开始，快慢指针同步前行，相交点即是环的入口

142.环形链表2，detectCircle
数据结构：快慢指针
算法：快慢指针法
思路：快慢指针是否相交，相交后两指针位置距离正好等于链表环的长度，将慢指针从头开始，快慢指针同步前行，相交点即是环的入口

146.LRU缓存，LRUCache
数据结构：双向链表 + 哈希表
算法：LRU算法
思路：addToHead(), moveToHead(), removeNode(), removeTail()
因为会频繁操作头、尾节点，因此设置头尾哑结点，便于移动头结点和删除尾节点！

148.排序链表，sortList
数据结构：链表 + 快慢指针
算法：归并分治算法
思路：快慢指针进行二分，归并进行合并链表

149.直线上最多的点数
数据结构：哈希表
算法：本质上是找相同斜率最多的点，那么可以对斜率进行分组统计，斜率如何表示呢，可以对delta_x, delta_y进行化简（最大公约数，再哈希），这样就得到斜率的表示。统计斜率的的节点数即可。当当前最多的节点数已经最大了，即剩余的节点数还没有当前同一个斜率的节点数多，那么后续节点也就没有处理的必要了，剪枝退出，返回答案。

150.逆波兰表达式求值
数据结构：栈
算法：遇到二元预算符时，弹出两个数字，进行计算再回填栈中。

152.乘积最大子数组，maxProduct
数据结构：数组
算法：动态规划
思路：维护两个动态规划数组，一个表示较大乘积，一个表示较小乘积

155.最小栈，MinStack
数据结构：栈
算法：迭代
思路：维护两个栈，一个用于存储栈元素一个用于存储最小值

160.相交链表，getIntersectionNode
数据结构：链表
算法：双指针迭代
思路：当两个指针不等时循环遍历，走到链表末尾时互换指针，保证两个指针最多只走l1 + l2步；
退出循环时若两个指针都为null，则不想交，否则即为相交节点

162.寻找峰值
数据结构：数组
算法：二分查找
思路：找到峰值（nums[mid-1] < nums[mid] > nums[mid+1）则返回mid，否则根据mid判断向左走还是向右走。

166.分数到小数
数据结构：哈希表
算法：哈希表计算循环小数
思路：分数肯定是有理数，即有限小数和循环小数。
第一步：先计算整数部分
第二步：小数部分使用哈希表记录余数（或除数都行，余数更方便）是否重复，若为有限小数，则某一时刻余数必为0，若为循环小数，则某一时刻余数必重复。
第三步：最后判断余数是否为0判定是否为循环小数，并对循环小数加入特定标志。

169.多数元素，majorityElement
数据结构：哨兵指针和计数器
算法：哨兵法
思路：遇到相同元素时+1，不相同元素时，计数器-1，这样做的思路是：对于多数元素问题，消除两个不同元素，不改变问题的结果。
同理：个数超过n/3的元素，也是可以通过两个哨兵的方法找出来

172.阶乘后的0
算法：迭代
思路：每隔一个5，就会出现一个2*5的组合，末尾一个0；
每隔一个25，就会出现一个5*5的组合，末尾两个0；
每隔一个125，就会出现一个5*5*5的组合，末尾三个0；
因此末尾0的个数 = n/5 + n/25 + n/125 + ...

179.最大数
数据结构：数组
算法：快排算法
思路：需要自定义快排的比较函数，为两个数字放前或放后的大小，即 left + right > right + left ? 1 : -1;

189.轮转数组
数据结构：数组
算法：最大公约数 + 迭代
思路：从一个位置开始循环替换，肯定会返回到起始位置，那会不会有些位置始终不会被替换呢。会有gcd(n, k)个。

190.颠倒二进制位
数据结构：整型
算法一：迭代
思路一：循环遍历颠倒二进制，累加结果

算法二：分治法
思路二：最底层左右两两交换，所以掩码是奇偶；倒数第二层左右对交换，所以掩码是奇偶对；
依次类推，最上层左右16位互换。

191.位1的个数
算法：异或
思路：与比特位计数题相同

198.打家劫舍，rob
数据结构：数组
算法：动态规划
思路：两个动态规划数组，分别表示偷与不偷的收益

200.岛屿数量，numIslands
数据结构：二维数组自身状态标记（无需开辟新空间）+ 队列
算法一：宽度优先遍历
思路一：用队列queue进行宽度遍历，遍历后将值标记为’0‘，避免重复遍历，计算遍历的深度，即岛屿的个数。

算法二：深度优先遍历
思路二：对dfs深度遍历，被遍历过的值标记为0，计算岛屿数

202.快乐数
数据结构：哈希表
算法一：下一位 + 哈希表
思路一：快乐数要么为1要么会循环，不可能无限不循环（因为平方和在收敛“变小”，所以要么收敛到1，要么循环）。所以我们需要用哈希表判断是否循环或收敛到1即可。

算法二：快慢指针（Floyd判圈）
思路二：思路同思路一

204.计数质数
算法一：质数原始解法
思路一：逐个判定是否为质数

算法二：动态规划-埃氏筛
思路二：
第一步：初始时所有数字都为质数
第二步：遍历，若一个数字为质数，那么它的倍数一定不是质数，即2x、3x...，同时我们会发现，2x、3x在判定质数2、3的时候已经标记过一次了，因此直接从x*x、(x+1)*x开始标记即可。这就是动态规划的转移方程。

206.反转链表，reserveList
数据结构：链表指针
算法一：迭代
思路一：指针pre，cur，next，改变链表的方向

算法二：递归调用
思路二：
node = reserve(head->next);
head->next->next = head;
head->next = nullptr;

dfs图示：
head -×-> next <- node <- tail
  ^--------|

207.课程表，canFinish
数据结构：哈希表 + 队列queue or 数组
算法一：宽度优先遍历
思路一：bfs，用哈希表统计每个课程的入度，将入度为零的课程放入队列中，依次处理队列中的课程，并对下游课程入度减1，如果为0，则放入队列，当所有课程都处理完了，返回true，否则返回false。

算法二：深度优先遍历（即Floyd判圈算法）
思路二：dfs：首先，哈希表构造课程的”边“依赖关系，为递归调用做准备，数组为状态表，判断是否有环路，无有则把课程放入结果集中，最后判断课程是否全部处理完成。

208.实现Trie树，Trie
数据结构：数组（多叉树的类）
算法：多叉树 + 迭代
思路：迭代插入和搜索

210.课程表2
数据结构：哈希表 + 队列
算法一：宽度优先遍历
思路一：同207题
算法二：深度优先遍历（Floyd判圈算法）
思路二：同207题

212.单词搜索2
数据结构：前缀树
算法一：深度优先遍历
思路一：考虑字符串数组在矩阵上进行查找，常规的查找办法是且矩阵遍历常常使用深度递归遍历
TODO

215.数组中第K大元素，findKthLargest
数据结构：数组 + 快排指针
算法：快排 or 堆排

217.存在重复元素
数据结构：哈希表
算法：哈希查找

218.天际线问题
题目要求：”输出每个矩形的上边左端点，同时跳过可由前一矩形上边延展而来的那些边”
数据结构：所以需要维护一个最大高度的优先队列
算法：线扫描法
思路：
第一步：构建建筑物的边缘数组，并从左往右排序（用于线扫描）
第二步：线扫描，遍历边缘数组，并用优先队列存储该条线上的建筑物，
（2.1）加入左边界在线上的建筑；
（2.2）弹出右边界不在线上的建筑；
（2.3）优先队列对顶建筑的最大高度，即是天际线。

221.最大正方形，maximalSquare
数据结构：二维数组
算法：动态规划
思路：dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])

226.翻转二叉树，invertTree
数据结构：二叉树
算法：深度优先遍历dfs

229.多数元素2（大于n/3的数），majorityElement
数据结构：两个哨兵
算法：贪心
思路：剔除三个不相同的数，不改变问题的结果

230.二叉搜索树中的第k小的数
数据结构一：栈
算法一：迭代法中序遍历
思路一：中序遍历第k个数即是答案

数据结构二：哈希表
算法二：预处理二叉树结点个数 + 二分查找
思路二：
第一步：预处理二叉树，计算各节点的个数
第二步：通过左右查找，找到第k个数

234.回文链表，isPalidrom
数据结构：链表 + 快慢指针
算法：快慢指针 + 反转链表
思路：快慢指针找出中点，然后翻转链表，比较是否相等，最后将翻转过的链表在翻转回去。

236.二叉树的最近公共祖先，lowestCommonAncester
数据结构：二叉树
算法：深度优先遍历
思路：遇到p或q则返回该节点，如果孩子节点分别是p和q则返回root节点，都不是则返回nullptr
（保证树上要么是p，要么是q，要么是他们的祖先）

237.删除链表中的节点
数据结构：链表
算法：迭代
思路：因为无法获取head节点，所以只能从node节点开始移位操作，最后一位删除即可。为了能够删除最后一位，则需要维护pre节点的指针。

238.除自身以外数组的乘积，productExceptSelf
数据结构：数组
算法：动态规划
思路：利用输出数组作为动态规划的dp数组，第一遍计算得到左边的乘积，第二遍计算得到右边的乘积

239.滑动窗口最大值，maxSlidingWindow
数据结构一：单调数组
算法一：单调队列
思路一：每次滑动时，先与队列尾部元素比较，弹出较小的，最后判定队列首元素的失效性，然后去队首即为滑窗最大值。

数据结构二：
算法二：分块 + 预处理
思路二：将数组按滑窗大小进行分段，每个位置滑窗的最大值，由其滑窗前向的最大值和滑窗后向的最大值决定

240.搜索二维数组，searchMatrix
数据结构：二维数组
算法：二分查找
思路：向上或向右

242.有效的字母异位词
数据结构：哈希表或等价数组
算法：统计并比较

268.丢失的数字
数据结构：数组
算法：自身标记法
思路：数组位标志法，即将数字num对应的位置数+n+1，即不影响原来的值大小，又能标记该位置的数字已存在。

274.H指数
算法一：排序，O(nlogn)
思路一：第一步，预排序
第二步：计算H指数（即引用文章次数大于H次）

算法二：计数排序，O(n)
思路二：第一步，先计数。我们发现H指数不可能大于总论文数n，所以遇到引用次数大于n的，都记在n上即可。
第二步：后“按照计数排序”

279.完全平方数，numSquares
数据结构：数组（字典）
算法：动态规划（子问题优化）

283.移动零，moveZero
数据结构：数组 + 双指针
算法：一个指针前进，一个指针指向左侧0的边界位置

287.寻找重复数，findDuplicate
数据结构：数组
算法一：自身标记法
思路一：+n置标志位

算法二：Floyd判圈法
思路二：类似寻找有环链表、课程表问题

289.生命游戏
数据结构：二维数组
算法：自身标记法
思路：使用数组自身标记（既能保留原有的状态，又能表示复活或死亡状态）

295.数据流中的中位数
数据结构一：双优先队列
算法一：大顶堆+小顶堆
思路一：
1、大顶堆负责记录小于等于中位数的数，小顶堆负责维护大于中位数的数；
2、要注意交换堆顶元素，使得大小堆元素个数平衡；
3、所以最终的中位数，要么是大顶堆的堆顶（奇数时），要么是两个堆堆顶元素的均值（偶数时）。

数据结构二：有序集合multiset + 双指针
算法二：有序集合multiset + 双指针
思路二：有序集合multiset负责帮助数据流进行快速排序，左右指针指针实时更新指向中位数（奇数时左右指针相等，偶数时左右指针相邻）

297.二叉树的序列化和反序列化，Codec
数据结构：队列
算法：宽度优先遍历
思路：按照中序遍历进行序列化，使用队列queue进行反序列化

300.最长递增子序列，lengthOfLIS
数据结构一：数组
算法一：动态规划
思路一：数组dp[i]表示前i位最长递增子序列，因此可以推导出第i+1的最长递增长度，时间复杂度为O(n^2)

数据结构二：单调栈
算法二：单调栈 + 二分查找
思路二：利用单调栈维护递增数组，更新单调栈时，使用二分查找可以提高查询效率；单调栈的长度即为最长递增子序列的长度。

301.删除无效括号数，removeInvalidParentheses
数据结构：计数器
算法：深度优先遍历
思路：用计数器统计待删除的左右括号数，递归调用执行删除任务

309.最佳买卖股票时机含冷冻期，maxProfit
数据结构：数组或数字
算法：动态规划
思路：买的收益、卖的收益、什么也不操作的收益，即dp1为买入，dp2为卖出，dp3为冷冻期(什么也不操作)

312.戳气球，maxCoins
数据结构一：二维dp数组
算法一：动态规划
思路一：三维遍历，从戳气球逆向求解，dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + vals[i] * vals[k] * vals[j])

算法二：深度优先遍历

315.计算右侧小于当前元素的个数
数据结构一：数组
算法一：归并排序，O(nlogn)
思路一：
第一步：利用归并排序归并时计算逆序数，从大到小归并
第二步：子问题归并完成后更新到原始数组，同时更新元素下标索引，便于下次归并

数据结构二：栈，O(n^2)
算法二：单调递增栈
思路二：当栈元素被弹出或被移位时，即可更新逆序数

322.零钱兑换，coinChange
数据结构：二维数组
算法：动态规划
思路：dp[i] = min(dp[i], dp[i - coin] + 1)

324.摆动排序
数据结构一：数组
算法一：预排序 + 穿插
思路一：
第一步：对数组预排序
第二步：找出大小分界线，若数组个数为奇数，则最中间的数放在左边，然后左右两个子数组从大到小交叉排列即可。

数据结构二：数组
算法二：快排
思路二：
第一步：快排找出中位数；
第二步：分区将小数放在左侧，大数放在右侧；（因为并不需要完全排序，只要大数和小数分开即可）
第三步：逆序穿插

326.3的幂
算法一：迭代（循环除3）
思路一：循环被3整除，判定最后一个除数是否为1

算法二：数学关系
思路二：3的幂一定是最大幂3^19的约数，所以判定n > 0 && 3^19 % n == 0即可

328.奇偶链表
数据结构：链表
算法：双指针
思路：用双指针先将奇偶链表分离，再头尾合并

329.矩阵中的最长递增路径
数据结构：二维数组
算法：深度优先遍历
思路：带记忆功能的深度优先遍历dfs，一个矩阵负责记录栈访问过的元素，一个矩阵负责记录每个元素对应位置的最长递增路径长度！

334.递增三元子序列
数据结构一：数组
算法一：哨兵算法
思路一：
第一步：从左到右遍历数组，记录左边最小的数
第二步：从右到左遍历数组，记录右边最大的数
第三步：遍历数组，判定左边数 < 当前数 < 右边数

数据结构二：双指针
算法二：贪心算法 + 双指针
思路二：
当first < second < nums[i]则返回true；那么如何更新双指针呢？
当遇到的数大于first且小于等于second可以更新second；
当遇到的数小于first时，可以更新first。

337.打家劫舍，rob
数据结构：二叉树
算法：深度优先遍历 + 动态规划
思路：遍历二叉树，每个节点返回打劫与不打劫的收益，最终计算获得最大收益

338.比特位计数，countBits
数据结构：数组
算法一：与运算直接计数法
思路一：与运算不停消除最低有效位，并计数

算法二：动态规划-最高有效位
思路二：记录最高有效位
if(i & (i-1) == 0) {
  highBit = i;
}
res[i] = res[i - highBit] + 1;

算法三：动态规划-最低有效位
思路三：
res[i] = res[i >> 1] + i & 1;

算法四：动态规划-最低有效位
思路四：
res[i] = res[i & (i - 1)] + 1;

341.扁平化嵌套列表迭代器
输入数据结构：嵌套数据结构
数据结构：栈
算法：递归或迭代
思路：因为是嵌套数据结构很容易想到递归或者迭代（栈）

344.反转字符串
数据结构：字符串
算法：调用库函数reverse

347.前k个高频元素，topKFrequent
数据结构：哈希表
算法：快排
思路：先用哈希表统计计数，然后快排，找到第k大的元素

350.两个数组的交集2
数据结构一：哈希表
算法一：哈希表 + 迭代
思路一：
第一步：哈希表计数
第二步：记录交集个数

371.两整数之和
数据结构：整数
算法：数学关系
思路：
第一步：两数异或，表示“结果”
第二步：两数相与，并左移一位表示“进位”
第三步：递推，完成“结果”和“进位”两数的加和

378.有序矩阵中第k小的元素
数据结构：矩阵
算法：二分查找
思路：
第一步：matrix[0][0]为左边界，matrix[n-1][n-1]为右边界；
第二步：判定mid是否为第k小的数，若是则返回，否则按照条件更新左右边界。

380.O(1)的时间插入、删除和获取随机元素
数据结构：数组 + 哈希表
算法：数据关系法
思路：数组负责存储数据和随机查找；哈希表负责维护数据关系（索引）

384.打乱数组
数据结构：数组
算法：洗牌算法
思路：每次从剩余的位置随机选择一个放到当前位，这样就完成了一次shuffle洗牌。

387.字符串中的第一个唯一字符
数据结构：哈希表
算法：哈希表
思路：哈希表记录元素重复情况及下标，最后遍历找出下标最小的字符

394.字符串解码，stringDecode
数据结构一：字符串
算法一：深度优先遍历
思路一：
第一步：当遇到中括号'['即是递归调用的开始；
第二步：']'或者字符串结束则表示本层递归调用结束；
第三步：遇到整数则对字符串进行复制。

数据结构：字符串 + 栈
算法二：栈（迭代法实现递归过程）
思路二：
第一步：当遇到']'则表示递归调用一层结束，需要弹出字符串和数字，对字符串进行复制后，再放入栈中，作为上一层递归调用的使用；
第二步：遇到其他字符串，则直接入栈。

395.至少有k个重复字符的最长子串
数据结构一：二维数组（代替哈希表）
算法一：前缀记忆搜索
思路一：
第一步：利用前缀记忆搜索，判定prefix[i]和prefix[j]的字符串是否是满足重复k个；
第二步：更新子串长度。

数据结构二：数组
算法二：递归分治
思路二：
第一步：先统计字符串各字符的数量
第二步：找出第一个不满足重复k的字符，并用它对字符串进行切分；找不到则说明字符串满足条件；
第三步：递归调用，然后更新长度。

399.除法求值，calcEquation
数据结构一：队列queue
算法一：宽度优先遍历
思路一：利用队列queue，进行宽度优先遍历，当找到的子节点与被除数相等时，即有除法解。
第一步：节点编码；
第二步：建立边的关系，并存储除数；
第三步：宽度优先搜索，计算结果。

数据结构二：二维数组（图）
算法二：Floyd算法
思路二：
第一步：节点编码；
第二步：建立图关系，并存储除法值；
第三步：Floyd三层循环预处理，得到每个节点之间的除法值；
第四步：查找结果。

数据结构三：数组 + 数字型哈希表（即下标为key）
算法三：并查集
思路三：
第一步：节点编码；
第二步：并查集初始化；
第三步：路径压缩，边查边更新节点的关系和权值。

406.根据身高重建队列，reconstructQueue
数据结构：二维数组
算法一：预排序（从大到小排序）
思路一：
第一步：预排序，按照身高从大到小，按照人数从小到大排序；
第二步：根据人数，在相应位置上直接插入即可；
因为从大到小排序，后插入的身高低的，会改变右侧已插入身高高的元素的位置，但不会影响”人数关系“

算法二：预排序（从小到大排序）
思路二：
第一步：预排序，按照身高从小到大，人数从大到小排序；
第二步：按人数遍历空位去插入；
因为这样先插入身高低的，后插入身高高的，不会影响”人数关系“

416.分割等和子集，canPartition
数据结构：数组
算法：动态规划
思路：分割等和，即找寻能组成和为target = tsum / 2的子集，使用动态规划，从右往左找即可（避免数字被重复选取）

437.路径总和，pathSum
数据结构：二叉树 + 哈希表
算法：深度优先遍历 + 前缀和记忆
思路：用前缀和记录，二叉树深度遍历过程中的和，当前缀和 + target = curSum时，即有满足和为target的路径

438.找到字符串中所有字母异位词，findAnagrams
数据结构：字符串 + 哈希表
算法：迭代
思路：用一个哈希表计数器，记录待查找的字母异位词个字母的个数，然后固定滑窗遍历字符串去比较是否满足，如是则放入结果中。

448.找到所有数组消失的数字，findDisappearedNumbers
数据结构一：数组
算法一：数组标记法-加n取余标记法
思路一：将数组元素对应位置的元素+n，即标记正确的元素，剩余的未被标记的则为消失的数字。

数据结构二：数组
算法二：数组标记法-交换标记法
思路二：把数组元素交换到正确的位置上去，剩余的未正确放置的元素即是消失的数字。

454.四数相加2
数据结构：哈希表
算法：两两组合，两两查找，把O(n^4)问题，降为O(n^2)问题。

461.汉明距离，hammingDistance
数据结构：二进制
算法：异或 + 二进制计数法
思路：
第一步：先异或；
第二步：统计二进制比特位数。

494.目标和，findTargetSumWays
数据结构：数组
算法：动态规划
思路：因为本题的目标和，是数组元素可加可减的，所以本质上是求new target = tsum - target。然后使用动态规划即可，类比416题。

538.把二叉搜索树转换成累加树，convertBST
数据结构：二叉树
算法：深度优先遍历
思路：右根左遍历（逆中序遍历）

543.二叉树的直径，diameterOfBinaryTree
数据结构一：二叉树
算法一：深度优先遍历
思路一：通过递归调用计算二叉树深度，叶子结点返回深度为1

数据结构二：二叉树 + 队列
算法二：宽度优先遍历
思路二：根据宽度优先遍历的层次次数，得到二叉树的深度

560.和为k的子数组，subarraySum
数据结构：数组 + 哈希表
算法：前缀和算法
思路：类比437题二叉树的路径总和，通过前缀和哈希表维护历史累加的和，当curSum = k + preSum时，即找到和为k的连续数组了。

581.最短无序子数组，findUnsortedSubarray
数据结构：数组
算法：迭代
思路一：
第一步：从左往右找到波谷；
第二步：从右往左找到波峰；
第三步：从左往右找到比波谷大的第一个数，即无序子数组的左边界；
第四步：从右往左找到比波峰小的第一个数，即无序子数组的右边界；
第五步：计算闭区间长度。

思路二：无序子数组必然存在于左右两端有序的数组之间；
第一步：从左到右找出右边界及无序数组的上界maxn；
第二步：从右到左找出左边界及无序数组的下界minn；
第三步：计算闭区间长度。

617.合并二叉树，mergeTrees
数据结构：二叉树
算法：深度优先遍历

621.任务调度器，leastInterval
数据结构：数组 + 哈希表
算法：贪心算法（优先最近的大任务）
思路：
第一步：初始化构造任务下次执行时间（数组，因为任务有冷却时间）和任务剩余任务数（数组）
第二步：执行任务的贪心策略是：最近能执行的任务中剩余任务数最多的任务，所以：
（2.1）找出最近任务能执行的时间，并累加任务耗时
（2.2）在最近能执行的时间内找出任务数最多的任务
第三步：更新任务状态，包括下次执行时间和剩余任务数。

647.回文子串，countSubstrings
数据结构：字符串
算法：迭代
思路：分别以(i,i)和（i，i+1)为中心搜寻回文子串，记录个数

739.每日温度，dailyTemperatures
数据结构：数组 + 单调栈
算法：单调栈计算边界法
思路：用单调递减栈维持还没有找到右边界的左数，找到后依次弹出，并记录弹出左数的右边界
