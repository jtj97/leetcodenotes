# 剑指Offer10-II. 青蛙跳台阶:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)  
**题目描述：**  
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 `n` 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例**
```
输入：n = 2
输出：2

输入：n = 7
输出：21
```

## 自解——记忆化搜索：  
```cpp
class Solution {
public:
    vector<int> S = {1,1};
    int numWays(int n) {
        if(S.size()>n){
            return S[n];
        } else {
            S.emplace_back(numWays(n-1)%int((1e9)+7) + numWays(n-2)%int((1e9)+7))%int((1e9)+7);
        }
        return (numWays(n-1)%int((1e9)+7) + numWays(n-2)%int((1e9)+7))%int((1e9)+7);
    }
};
```

## DP:  
由于 `dp` 列表第 `i` 项只与第 `i-1` 和第 `i-2` 项有关，因此只需要初始化三个整形变量 `sum, a, b` ，利用辅助变量 `sum` 使 `a, b` 两数字交替前进即可 （具体实现见代码） 。
因为节省了 `dp` 列表空间，因此空间复杂度降至 `O(1)`。  
```java
class Solution {
    public int numWays(int n) {
        int a = 1, b = 1, sum;
        for(int i = 0; i < n; i++){
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
}
```