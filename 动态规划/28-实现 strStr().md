### [28\. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

Difficulty: **简单**


实现  函数。

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  `-1`。

**说明：**

当 `needle` 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 `needle` 是空字符串时我们应当返回 0 。这与 C 语言的  以及 Java 的  定义相符。

**示例 1：**

```
输入：haystack = "hello", needle = "ll"
输出：2
```

**示例 2：**

```
输入：haystack = "aaaaa", needle = "bba"
输出：-1
```

**示例 3：**

```
输入：haystack = "", needle = ""
输出：0
```

**提示：**

*   `0 <= haystack.length, needle.length <= 5 * 10<sup>4</sup>`
*   `haystack` 和 `needle` 仅由小写英文字符组成


#### Solution

[有限状态机,KMP](https://labuladong.gitbook.io/algo-en/v/master/dong-tai-gui-hua-xi-lie/qi-ta-jing-dian-wen-ti/dong-tai-gui-hua-zhi-kmp-zi-fu-pi-pei-suan-fa)

```cpp
​class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(26,0)); // dp[i][j]表示当前在第i个状态，字符为j+'a'，会跳到dp[i][j]状态
        dp[0][needle[0]-'a'] = 1;
        int X = 0;
        for(int i=1; i<n; ++i){
            for(int j=0; j<26; ++j){
                dp[i][j] = dp[X][j];
            }
            dp[i][needle[i]-'a'] = i + 1;
            X = dp[X][needle[i]-'a'];
        }
        int end = 0;
        for(int i=0; i<m; ++i){
            end = dp[end][haystack[i]-'a'];
            if(end==n){
                return i - n + 1;
            }
        }
        return -1;
    }
};
```