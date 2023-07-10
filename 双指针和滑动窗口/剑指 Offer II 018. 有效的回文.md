### [剑指 Offer II 018\. 有效的回文](https://leetcode-cn.com/problems/XltzEq/)

Difficulty: **简单**


给定一个字符串 `s` ，验证 `s` 是否是 **回文串 **，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 **回文串 **。

**示例 1:**

```
输入: s = "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
```

**示例 2:**

```
输入: s = "race a car"
输出: false
解释："raceacar" 不是回文串
```

**提示：**

*   `1 <= s.length <= 2 * 10<sup>5</sup>`
*   字符串 `s` 由 ASCII 字符组成

注意：本题与主站 125 题相同： 


#### Solution

忽略大小写。

```cpp
​class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        auto isSame = [](char a, char b){
            if(a>='A' && a<='Z') a += ('a'-'A');
            if(b>='A' && b<='Z') b += ('a'-'A');
            return a==b;
        };
        int l = 0, r = s.size() - 1;
        while(l<r){
            while(l<r && !isalpha(s[l]) && !isdigit(s[l])) ++l;
            while(l<r && !isalpha(s[r]) && !isdigit(s[r])) --r;
            if(l<r && !isSame(s[l], s[r])) return false;
            ++l;
            --r;
        }
        return true;
    }
};
```