# 剑指Offer63. 股票的最大利润：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/)  
**题目描述：**  
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？  

**示例:**
```  
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
```

## 解——DP:  
![](./Pic/63.png)  
显然，如果我们真的在买卖股票，我们肯定会想：如果我是在历史最低点买的股票就好了！太好了，在题目中，我们只要用一个变量记录一个历史最低价格 `minprice`，我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 `prices[i] - minprice`。

因此，我们只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：如果我是在历史最低点买进的，那么我今天卖出能赚多少钱？当考虑完所有天数之时，我们就得到了最好的答案。  
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9;
        int profit = 0;
        for(int price: prices){
            minPrice = min(minPrice, price);
            profit = max(profit, price-minPrice);
        }
        return profit;
    }
};
```

二刷:  
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int maxPro = 0;
        int minBuy = prices[0];
        for(int price : prices){
            maxPro = max(maxPro, price - minBuy);
            minBuy = min(minBuy, price);
        }
        return maxPro;
    }
};
```