# 剑指Offer57II. 和为s的连续正数序列：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)    
**题目描述：**  
输入一个正整数 `target` ，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。  

**示例：**  
```
输入：target = 9
输出：[[2,3,4],[4,5]]

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
```

## 暴力解：
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int end = target / 2 + 1;
        vector<vector<int>> result;
        vector<int> temp;
        int res;
        for(int i=1; i<end; i++){
            res = 0;
            temp.clear();
            for(int j=i; res<=target; j++){
                res += j;
                temp.push_back(j);
                if(res==target){
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
```

## 优化——滑动窗口：  
我们用两个指针 $l$ 和 $r$ 表示当前枚举到的以 $l$ 为起点到 $r$ 的区间，$sum$ 表示 $[l,r]$ 的区间和，由求和公式可求得 $sum=\frac{(l+r)\times (r-l+1)}{2} $， 起始$l=1,r=2$  
一共有三种情况：  
* 如果 $sum<target$ 则说明指针 $r$ 还可以向右拓展使得 $sum$ 增大，此时指针 $r$ 向右移动，即 `r += 1`
* 如果 $sum>target$ 则说明以 $l$ 为起点不存在一个 $r$ 使得 $sum=target$， 此时要枚举下一个起点，指针 $l$ 向右移动，即 `l += 1`
* 如果 $sum=target$ 则说明$[l,r]$为合法解。  
![](./Pic/57.jpg)
我们一开始要找的是 1 开头的序列，只要窗口的和小于 target，窗口的右边界会一直向右移动。假设 $1+2+\cdots+8$ 小于 target，再加上一个 9 之后， 发现 $1+2+\cdots+8+9$ 又大于 $target$ 了。这说明 $1$ 开头的序列找不到解。此时滑动窗口的最右元素是 $9$。
接下来，我们需要找 2 开头的序列，我们发现，$2 + \dots + 8 < 1 + 2 + \dots + 8 < target$ 。这说明 2 开头的序列至少要加到 9。那么，我们只需要把原先 1~9 的滑动窗口的左边界向右移动，变成 2~9 的滑动窗口，然后继续寻找。而右边界完全不需要向左移动。  
以此类推，滑动窗口的左右边界都不需要向左移动，所以这道题用滑动窗口一定可以得到所有的解。




**Note** :使用`emplace_back()`代替`push_back()`更快。
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>vec;
        vector<int> res;
        for (int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target) {
                res.clear();
                for (int i = l; i <= r; ++i) {
                    res.emplace_back(i);
                }
                vec.emplace_back(res);
                l++;
            } else if (sum < target) {
                r++;
            } else {
                l++;
            }
        }
        return vec;
    }
};
```


二刷:  
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l = 1, r = 1, sum = 0;
        vector<vector<int>> res;
        while(r<target){
            sum += r;
            while(sum>=target){
                if(sum==target){
                    vector<int> tmp;
                    for(int i = l; i <= r; ++i){
                        tmp.emplace_back(i);
                    }
                    res.emplace_back(tmp);
                }
                sum -= l;
                ++l;
            }
            ++r;
        }
        return res;
    }
};
```