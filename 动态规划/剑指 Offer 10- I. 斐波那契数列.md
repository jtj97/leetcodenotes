# 剑指Offer10-II. 斐波那契数列:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)  
**题目描述：**  
写一个函数，输入 `n` ，求斐波那契（Fibonacci）数列的第 `n` 项（即 `F(N)`）。斐波那契数列的定义如下：
```
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
```

## 自解——DP:  
```cpp
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, tmp;
        for(int i=0; i<n; i++){
            tmp = (a + b) % int(1e9 + 7);
            a = b % int(1e9 + 7);//此处不需要取余a = b
            b = tmp;
        }
        return a;
    }
};
```

二刷  
```cpp
class Solution {
private:
    const int mod = 1000000007;
public:
    int fib(int n) {
        if(n<2) return n;
        int dp_n_2 = 0, dp_n_1 = 1, dp_n = dp_n_2 + dp_n_1; //dp[2]
        for(int i=2; i<n; ++i){
            dp_n_2 = dp_n_1;
            dp_n_1 = dp_n;
            dp_n = (dp_n_2 + dp_n_1) % mod;
        }
        return dp_n;
    }
};
```