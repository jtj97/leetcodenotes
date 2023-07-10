# 剑指Offer16. 数值的整数次方：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)  
**题目描述：**  
实现 `pow(x, n)` ，即计算 `x` 的 `n` 次幂函数（即，$x^n$）。不得使用库函数，同时不需要考虑大数问题。
**示例:**  
```
示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
```

## 快速幂：  
[Link](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/mian-shi-ti-16-shu-zhi-de-zheng-shu-ci-fang-kuai-s/)  
二分法理解：  
$x^n=x^{n/2} \times x^{n/2}=(x^2)^{n/2}$，令$n/2$为整数则需要分为奇偶两种情况（设向下取整除法符号为 "$//$" ）：  
    当 $n$ 为偶数：$x^n=(x^2)^{n//2}$
    当 $n$ 为奇数：$x^n=x(x^2)^{n//2}$，即多出一项$x$
![](./Pic/16.png)  
转化为位运算：
向下整除$n//2$等价于右移一位$n>>1$
取余数$n\%2$等价于判断二进制最右一位值$n\&1$

循环过程：  
当$n\&1=1$,$res*=x$
执行$x*=x$
执行$n>>1$
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0){
            return 0;
        }
        long long n1 = n;
        if(n1<0){
            x = 1 / x;
            n1 *= -1;
        }
        double res = 1;
        while(n1!=0){
            if((n1&1)==1){
                res *= x;
            }
            x *= x;
            n1 = n1>>1;
        }
        return res;
    }
};
```
注意，使用long防止取负号越界。


二刷:  
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        bool isNegative = n < 0 ? true : false;
        long long newN = static_cast<long long>(n);
        newN = abs(newN);
        double res = 1;
        while (newN > 0) {
            if (newN % 2 == 0) {
                x *= x;
                newN /= 2;
            } else {
                res *= x;
                --newN;
                }
        }
        return isNegative ? 1.0 / res : res;
    }
};
```