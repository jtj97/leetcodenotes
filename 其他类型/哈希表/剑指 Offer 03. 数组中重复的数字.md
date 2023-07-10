# 剑指Offer03. 数组中重复的数字：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)  
**题目描述：**  
找出数组中重复的数字。  
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
**示例：**  
```
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
```

## 自解——哈希表：
利用哈希表储存已经遍历过的值，对key进行查询。
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int len = nums.size();
        int result=0;
        for(int i=0; i<len; i++){
            if(hashmap.find(nums[i])==hashmap.end()){
                hashmap.insert(make_pair(nums[i], 1));
            } else if(hashmap.find(nums[i])!=hashmap.end()){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};
```

## 原地交换：
题目说明尚未被充分使用，即 `在一个长度为 n 的数组 nums 里的所有数字都在 0 ~ n-1 的范围内` 。 此说明含义：数组元素的 **索引** 和 **值** 是 一对多 的关系。
因此，可遍历数组并通过交换操作，使元素的 **索引** 与 **值** 一一对应（即 $nums[i] = inums[i]=i$ ）。因而，就能通过索引映射对应的值，起到与字典等价的作用。
遍历中，第一次遇到数字 $x$ 时，将其交换至索引 $x$ 处；而当第二次遇到数字 $x$ 时，一定有 $nums[x] = xnums[x]=x$ ，此时即可得到一组重复数字。
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};
```

二刷——原地交换（一刷的实现更好）:  
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]!=i){
                if(nums[i]==nums[nums[i]]) return nums[i];
                else{
                    swap(nums[i], nums[nums[i]]);
                    --i;
                }
            }
        }
        return -1;
    }
};
```