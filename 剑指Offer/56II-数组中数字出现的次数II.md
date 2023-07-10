# 剑指Offer56II. 数组中数字出现的次数II：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)  
**题目描述：**  
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。  
**示例：**  
```
输入：nums = [3,4,3,3]
输出：4

输入：nums = [9,1,7,9,7,9,7]
输出：1
```
## 自解:  
思路：对nums排序，每隔3个检查该元素与后1元素是否相等（如果是最后一个元素直接返回最后一元素），如果不等，则返回该元素。  
时间复杂度O(nlogn)
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if(len==1){
            return nums[0];
        }
        for(int i=0; i<len; i=i+3){
            if(i==len-1){
                return nums[i];
            }
            if(nums[i]==nums[i+1]){
                continue;
            } else {
                return nums[i];
            }
        }
        return 0;
    }
};
```

## O(n)解法：
哈希表：  
统计所有数字的次数，采用key ： value的方式存在哈希表中  
扫描哈希表，找出只出现一次的那个数字  
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n : nums) mp[n] ++;
        int ans;
        for(auto pr : mp){
            if(pr.second == 1){
                ans = pr.first;
                break;
            }
        }
        return ans;
    }
};
```

位运算：  
如下图所示，考虑数字的二进制形式，对于出现三次的数字，各 二进制位 出现的次数都是 3 的倍数。
因此，统计所有数字的各二进制位中 1 的出现次数，并对 3 求余，结果则为只出现一次的数字。  
![](./Pic/56II.png)
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(int n : nums){
                // n & 1 << i 的值大于0即为真
                if(n & (1 << i)) cnt++;
            }
            // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
            if(cnt % 3 == 1) ans ^= (1 << i);
        }
        return ans;
    }
};
```
