# 剑指Offer05. 替换空格:
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)    
**题目描述：**  
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。  
**示例：**  
```
输入：s = "We are happy."
输出："We%20are%20happy."
```

## 自解:  
```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string result;
        for(char c : s){
            if(c==' '){
                result = result + "%20";
            } else {
                result = result + c;
            }
        }
        return result;
    }
};
```