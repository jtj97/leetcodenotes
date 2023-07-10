# 剑指Offer11. 旋转数组的最小数字:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)  
**题目描述：**  
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个**递增排序**的数组的一个旋转，输出旋转数组的最小元素。例如，数组` [3,4,5,1,2] `为` [1,2,3,4,5] `的一个旋转，该数组的最小值为`1`。  
**示例:**  
```
输入：[3,4,5,1,2]
输出：1

输入：[2,2,2,0,1]
输出：0
```

## 自解——二分查找：  
1.思路同剑指offer53-1在排序数组中查找数字。
如果`mid`处元素大于`right`处元素，则说明left还没到旋转后第二个递增部分数组。如果`mid`处元素小于`right`处元素，则说明right在递增数组中。如果`mid`处元素等于`right`处元素，则说明有连续相同元素。

2.[详细解答](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-by-leetcode-s/)  
我们考虑数组中的最后一个元素 `x`：在最小值右侧的元素，它们的值一定都小于等于 `x`；而在最小值左侧的元素，它们的值一定都大于等于 `x`。因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。  
第一种情况是$numbers[mid]<numbers[high]$  这说明$numbers[mid]$是最小值右侧的元素，因此我们可以忽略二分查找区间的右半部分。
第二种情况是$numbers[mid]>numbers[high]$ 这说明$numbers[mid]$ 是最小值左侧的元素，因此我们可以忽略二分查找区间的左半部分。
第三种情况是$numbers[mid]==numbers[high]$ 由于重复元素的存在，我们并不能确定$numbers[pivot] $ 究竟在最小值的左侧还是右侧，因此我们不能莽撞地忽略某一部分的元素。我们唯一可以知道的是，由于它们的值相同，所以无论$numbers[high]$是不是最小值，都有一个它的「替代品」$numbers[mid]$因此我们可以忽略二分查找区间的右端点。


```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty()){
            return 0;
        }
        int left = 0, right = numbers.size()-1, mid;
        while(left<=right){
            mid = left + (right - left) / 2;
            if(numbers[mid]>numbers[right]){
                left = mid + 1;
            } else if(numbers[mid]<numbers[right]){
                right = mid;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};
```
