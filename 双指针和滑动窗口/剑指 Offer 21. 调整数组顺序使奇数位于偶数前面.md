# 剑指Offer21. 调整数组顺序使奇数位于偶数前面:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/)  
**题目描述：**  
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
**示例：**  
```
输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
```

## 自解：  
```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> result;
        vector<int> even;
        for(int i:nums){
            if(i%2){
                result.emplace_back(i);
            } else {
                even.emplace_back(i);
            }
        }
        for(int i:even){
            result.emplace_back(i);
        }
        return result;
    }
};
```
优化想法：原地交换,j指向尾部,i指向头部,若为奇数i++，若为偶数则与尾部元素交换且j--，交换后再次判定i处，直到i>j  

## 实际优化：  
定义头指针 $left$ ，尾指针 $right$ .
$left$ 一直往右移，直到它指向的值为偶数
$right$ 一直往左移， 直到它指向的值为奇数
交换 $nums[left]$ 和 $nums[right]$.
重复上述操作，直到 $left == right$ .
```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left ++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right --;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};
```

## 二刷:  
```cpp
class Solution {
private:
    inline bool isOdd(int x){
        return x%2!=0;
    }
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<right){
            while(left<right && isOdd(nums[left])) ++left; //向后找到偶数
            while(left<right && !isOdd(nums[right])) --right; //向前找到奇数
            if(left<right) swap(nums[left], nums[right]);
            ++left;
            --right;
        }
        return nums;
    }
};
```