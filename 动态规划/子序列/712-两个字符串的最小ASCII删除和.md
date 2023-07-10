### [712\. 两个字符串的最小ASCII删除和](https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/)

Difficulty: **中等**


给定两个字符串`s1, s2`，找到使两个字符串相等所需删除字符的ASCII值的最小和。

**示例 1:**

```
输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
```

**示例 2:**

```
输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
```

**注意:**

*   `0 < s1.length, s2.length <= 1000`。
*   所有字符串中的字符ASCII值在`[97, 122]`之间。


#### Solution

逆向思考，类似于求最大公共子序列，先求`ASCII和最大的公共子序列`，然后用两个序列的ASCII和减去 **2倍** 的 `ASCII和最大的公共子序列和`·`

```cpp
​class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int t1 = s1.size(), t2 = s2.size();
        int ans = 0;
        for(char c: s1){
            ans += static_cast<int>(c);
        }
        for(char c: s2){
            ans += static_cast<int>(c);
        }
        vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0)); //dp[i][j]表示text1[0...i-1]和text2[0...j-1]字符串的最大ASCII和的公共子序列的ASCII和
        for(int i=1; i<=t1; ++i){
            for(int j=1; j<=t2; ++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + static_cast<int>(s1[i-1]);
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return (ans - 2 * dp[t1][t2]);
    }
};
```

#### Solution2

正向思考，`dp[i][j]`为`s1[0...i-1]`与`s2[0...i-2]`相同的最小ASCII删除和

```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = 0;
        for(int i=1; i<=m; ++i){
            dp[i][0] = dp[i-1][0] + static_cast<int>(s1[i-1]);
        }
        for(int j=1; j<=n; ++j){
            dp[0][j] = dp[0][j-1] + static_cast<int>(s2[j-1]);
        }
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i][j-1]+static_cast<int>(s2[j-1]), dp[i-1][j]+static_cast<int>(s1[i-1])); //分别是删除s2[j-1]和删除s1[i-1]
                }
            }
        }
        return dp[m][n];
    }
};
```