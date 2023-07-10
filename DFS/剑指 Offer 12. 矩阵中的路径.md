# 剑指Offer12. 矩阵中的路径:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)  
**题目描述：**  
给定一个 `m x n` 二维字符网格 `board` 和一个字符串单词 `word` 。如果 `word` 存在于网格中，返回 `true` ；否则，返回 `false` 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

**示例：**  
例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。  
![](./Pic/12_0.jpg)  
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```

## 自解DFS+回溯：  
思路大体同[剑指Offer13-机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)  
要点在于**还原当前矩阵元素**，这是回溯法很重要的步骤。  
破坏现场 -> dfs -> 还原现场  
破坏现场指的是给`board[i][j]`赋空值，然后dfs，还原现场指的是还原`board[i][j]`的值。  

**Trick:**
将
```cpp
bool dfs(int row, int col, int wordPos, vector<vector<char>>& board, string word);
```
改为
```cpp
bool dfs(int row, int col, int wordPos, vector<vector<char>>& board, string& word);
```
不然每次递归值需要拷贝，花费时间。

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rowM = board.size();
        colM = board[0].size();
        bool res=false;
        for(int row=0; row<rowM; row++){
            for(int col=0; col<colM; col++){
                if(board[row][col]==word[0]){
                    res = dfs(row, col, 0, board, word);
                    if(res==true){
                        return res;
                    }
                }
            }
        }
        return res;        
    }
private:
    int rowM;
    int colM;
    bool dfs(int row, int col, int wordPos, vector<vector<char>>& board, string word){
        if(row<0 || col<0 || rowM<=row || colM<=col || word[wordPos]!=board[row][col]){
            return false;
        }
        if(wordPos==word.length()-1){
            return true;
        }
        board[row][col] = '\0';
        bool res = dfs(row-1, col, wordPos+1, board, word) ||
            dfs(row+1, col, wordPos+1, board, word) ||
            dfs(row, col-1, wordPos+1, board, word) ||
            dfs(row, col+1, wordPos+1, board, word);
        board[row][col] = word[wordPos];
        return res;
    }
};
```


二刷：  
```cpp
class Solution {
private:
    int maxR, maxC;
    string target;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool DFS(vector<vector<char>>& board, int row, int col, string path){
        if(row<0 || col<0 || row>=maxR || col>=maxC || target[path.size()]!=board[row][col]){
            return false;
        }
        if (path.size()==target.size()-1) return true;
        char temp = board[row][col];
        path += board[row][col];
        board[row][col] = '#';
        bool res = false;
        for(const vector<int>& direction : directions){
            res = DFS(board, row + direction[0], col + direction[1], path);
            if(res) break;
        }
        board[row][col] = temp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->maxR = board.size();
        this->maxC = board[0].size();
        this->target = word;
        bool res = false;
        for(int i=0; i<maxR; ++i){
            for(int j=0; j<maxC; ++j){
                if(board[i][j]==word[0]){
                    res = DFS(board, i, j, "");
                }
                if(res) return true;
            }
        }
        return res;
    }
};
```