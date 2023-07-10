# 剑指Offer58II. 左旋转字符串：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)  
**题目描述：**   
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

**示例：**  
```
输入: s = "abcdefg", k = 2
输出: "cdefgab"

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
```

## 自解:
```
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string result;
        int len = s.length();
        for(int i=n; i<len;i++){
            result = result + s[i];
        }
        for(int i=0; i<n; i++){
            result = result + s[i];
        }
        return result;
    }
};
```

## 其他解——三次反转：
时间O(n), 空间O(1)  
![](./Pic/offer58II.png)  
```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
```

注：substr方法空间复杂度为O(n)


## 二刷:
反转具体实现用双指针  
```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        std::reverse(s.begin(), s.begin()+n);
        std::reverse(s.begin()+n, s.end());
        std::reverse(s.begin(), s.end());
        return s;
    }
};
···