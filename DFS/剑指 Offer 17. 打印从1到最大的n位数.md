### [剑指 Offer 17\. 打印从1到最大的n位数](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)

Difficulty: **简单**


输入数字 `n`，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

**示例 1:**

```
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
```

说明：

*   用返回一个整数列表来代替打印
*   n 为正整数


#### Solution

考虑大数版本，输出为vector<string>。  
如`0,1,2,3,4,5,6,7,8,9`

用BFS比DFS简单。


```cpp
​#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
 private:
  int maxLen;
  vector<string> nums{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  vector<string> res;
 public:
  Solution() = default;
  Solution(int x) : maxLen(x){};
  vector<string> printNumbers() {
    if(maxLen<1 || !res.empty()) return res;
    queue<string> q;
    for(string num : nums){
      q.emplace(num);
    }
    int len = 1;
    while(!q.empty()){
      int qSize = q.size();
      for(int i=0; i<qSize; ++i){
        string num = q.front();
        res.emplace_back(num);
        q.pop();
        if(num[0]!='0' && len<maxLen){
          for(string digit : nums){
            string temp = num+digit;
            q.emplace(temp);
          }
        }
      }
      ++len;
    }
    return res;
  }
};

int main() {
  int n = 3;  //位数
  Solution sol(n);
  vector<string> res = sol.printNumbers();
  for(int i=0; i<res.size(); ++i){
    cout<<res[i]<<"  ";
    if((i+1)%10==0) cout<<endl;
  }
  return 0;
}
```