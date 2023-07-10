### [171\. Excel表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number/)

Difficulty: **简单**


给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

```
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
```

**示例 1:**

```
输入: "A"
输出: 1
```

**示例 2:**

```
输入: "AB"
输出: 28
```

**示例 3:**

```
输入: "ZY"
输出: 701
```

**致谢：**  
特别感谢  添加此问题并创建所有测试用例。


#### Solution

相当于一个`26进制`的数转换成`10进制`的数

```cpp
​class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int weight = 1;
        for(int i = columnTitle.size()-1; i>=0; --i){
            sum += (columnTitle[i] - 'A' + 1) * weight;
            if(weight <= INT_MAX/26) weight *= 26;
        }
        return sum;
    }
};
```