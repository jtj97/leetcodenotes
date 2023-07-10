# 剑指Offer46. 把数字翻译成字符串：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)  
**题目描述：**  
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
**示例：**  
```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```

## 自解——递归：  
注意如`120320`中,`03`不被当作3被翻译
```cpp
class Solution {
public:
    int result=0;
    int translateNum(int num) {
        vector<int> nums;
        if(num==0){
            return 1;
        }
        while(num!=0){
            nums.emplace_back(num%10);
            num /= 10;
        }
        reverse(nums.begin(), nums.end());
        help(nums, 0, false);
        return result;
    }
    void help(vector<int> nums, int pos, bool ones){
        if(pos==nums.size()-1){//到达最后一位
            result++;
            return;
        }
        if(ones==true){
            help(nums, pos+1, false);
        }
        if(ones==false){
            help(nums, pos+1, false);
            int temp = nums[pos]*10+nums[pos+1];
            if(nums[pos]>0 && temp<=25){
                help(nums, pos+1, true);
            }
        }
        return;
    }
};
```

## DP:  
![](./Pic/46.png)  
对$x_1x_2x_3...x_n$,$dp[i]$ 代表以 $x_i$为结尾的数字的翻译方案数量
```java
class Solution {
    public int translateNum(int num) {
        String s = String.valueOf(num);
        int a = 1, b = 1;
        for(int i = 2; i <= s.length(); i++) {
            String tmp = s.substring(i - 2, i);
            int c = tmp.compareTo("10") >= 0 && tmp.compareTo("25") <= 0 ? a + b : a;
            b = a;
            a = c;
        }
        return a;
    }
}
```

自己实现CPP
```cpp
class Solution {
public:
    int translateNum(int num) {
        vector<int> nums;
        while(num!=0){
            nums.emplace_back(num%10);
            num /= 10;
        }
        reverse(nums.begin(), nums.end());
        int a=1, b=1; //a=d[0], b=d[1]
        int len = nums.size();
        for(int i=2; i<=len; i++){ //用<=考虑到最后一位也可能和前一位组成10~25之间的数
            int temp = nums[i-1] + nums[i-2] * 10;
            int sum = (temp>=10 && temp<=25) ? a+b : b;
            a = b;// a向前进1一位
            b = sum;
        }
        return b;
    }
};
```


二刷，动态规划:  
本题类似解码方法  
```cpp
class Solution {
public:
    int translateNum(int num) {
        string numString = to_string(num);
        int n = numString.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; ++i){
            dp[i] += dp[i-1];
            if(i>1 && numString[i-2]!='0' && ((numString[i-2]-'0')*10 + (numString[i-1]-'0'))<=25 ) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
```