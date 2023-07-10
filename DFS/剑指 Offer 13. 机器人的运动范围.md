# 剑指Offer13. 机器人的运动范围：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)  
**题目描述：**  
地上有一个m行n列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]` 。一个机器人从坐标 `[0, 0]` 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 `[35, 37]` ，因为3+5+3+7=18。但它不能进入方格 `[35, 38]`，因为3+5+3+8=19。请问该机器人能够到达多少个格子？  
**示例:**  
```
输入：m = 2, n = 3, k = 1
输出：3

输入：m = 3, n = 1, k = 0
输出：1
```

## DFS+回溯:  
1.前置:  
数位求和
```cpp
    int BAns(int x){
        int res = 0;
        while(x!=0){
            res += x % 10;
            x /= 10;
        }
        return res;
    }
```

在$1 \leq n,m \leq 100$范围下:
当$(x+1)⊙10=0 $, $ s_{x+1} = s_x - 8 $ , Eg.: 19,20位数和分别为10, 2
当$(x+1)⊙10!=0 $, $s_{x+1} = s_x + 1$
```cpp
(x + 1) % 10 != 0 ? s_x + 1 : s_x - 8;
```

2. DFS+回溯
只用向右和向下搜索。

### 未使用增量公式:  
```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(0, 0, visited, m, n, k);
    }
private:
    int BAns(int x){
        int res = 0;
        while(x!=0){
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    int dfs(int row, int col, vector<vector<bool>>& visited, int m, int n, int k){
        //递归终止
        if(m<=row || n<=col || k<BAns(row)+BAns(col) || visited[row][col]!=false){
            return 0;
        }
        visited[row][col] = true;
        return 1 + 
            dfs(row+1, col, visited, m, n, k) + 
            dfs(row, col+1, visited, m, n, k);
    }
};
```

### 使用增量公式：  
$si,sj$分别表示$i,j$按位和的结果。
```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(0, 0, 0, 0, visited, m, n, k);
    }
private:
    int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k) {
        if(i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
                   dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
    }
};
```