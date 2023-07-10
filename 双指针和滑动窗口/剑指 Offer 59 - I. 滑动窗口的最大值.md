# 剑指Offer59I. 滑动窗口的最大值：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/)  
**题目描述：**  
给定一个数组 `nums` 和滑动窗口的大小 `k`，请找出所有滑动窗口里的最大值。  
**示例：**  
```  
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```


## 单调队列:  
**思路:**  
每次滑动，相比于上次，会删掉最左边的元素，并添加进最右的新元素
因为要找窗口内的最大值，所以，如果加进来的新元素比左边的所有元素都大的话，那从此时开始，左边的元素全都没用了，它们不会成为此刻及以后的窗口的最大值了
如果加进来的新元素不是此时窗口的最大值的话，后面的窗口可能还会用到
以上所述，仔细想一想应该能明白吧！
抽象一下就是，我们只需要有效元素，也就是比它右边的所有元素都要大的元素
所以，这些有效元素，就是单调递减的了！相等的元素也没意义，严格单调递减就可以

**算法**
- 初始化： 双端队列 dequedeque ，结果列表 resres ，数组长度 nn ；
- 滑动窗口： 左边界范围 i∈[1−k,n−k] ，右边界范围 j∈[0,n−1] ；
    - 若 i > 0 且 队首元素 deque[0] == 被删除元素 nums[i−1] ：则队首元素出队；
    - 删除 deque 内所有 < nums[j] 的元素，以保持 deque 递减；
    - 将 nums[j] 添加至 deque 尾部；
    - 若已形成窗口（即 i≥0 ）：将窗口最大值（即队首元素 deque[0] ）添加至列表 res ；
- 返回值： 返回结果列表 res ；


```cpp
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        int n = nums.size();
        deque<int> d;
        k--; // 只是方便后面用
        for (int i = 0; i < n; i++)
        {
            // 删除不在窗口内的元素，无论它多大都没用了
            if (!d.empty() && d.front() < i - k)
            {
                d.pop_front();
            }

            // 添加元素，并保持队列是单调递减的
            while (!d.empty() && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);

            // 队列首部对应的元素为本窗口最大值，因为咱们一直保持队列是单调递减的嘛
            if (i >= k)
            {
                res.push_back(nums[d.front()]);
            }
        }
        return res;
    }
};
```


二刷:  
```cpp
class Solution {
    //维护一个单调递减双端序列
    // 5 3 2 新增 4 变成
    // 5 4   移5出窗口变成
    // 4 新增6变成
    // 6
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        deque<int> dq;
        vector<int> res;
        while(r<nums.size()){
            int newNum = nums[r];
            while(!dq.empty() && newNum>dq.back()){
                dq.pop_back();
            }
            dq.push_back(newNum);
            if(r-l==k-1){
                res.emplace_back(dq.front());
                int outNum = nums[l];
                if(dq.front()==outNum) dq.pop_front();
                ++l;
            }
            ++r;
        }
        return res;
    }
};
```

三刷:  
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> decreasingDQ;
        int l = 0, r = 0;
        vector<int> res;
        while(r < nums.size()){
            int num = nums[r];
            while(!decreasingDQ.empty() && num>decreasingDQ.back()) decreasingDQ.pop_back();
            decreasingDQ.push_back(num);
            while(r-l+1==k){
                res.push_back(decreasingDQ.front());
                if(nums[l]==decreasingDQ.front()) decreasingDQ.pop_front();
                ++l;
            }
            ++r;
        }
        return res;
    }
};
```