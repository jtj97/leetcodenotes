# 剑指Offer26. 树的子结构：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)  
**题目描述：**  
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。  
**示例:**  
```
例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
```

## 递归：
[Link](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/shu-de-zi-jie-gou-di-gui-zhan-mo-ni-by-huwt/)  
取母树为 AA ，子树为 BB ，需要判断 BB 是否为 AA 的子结构。

我们可以依次遍历 AA 中的所有结点，对每个在 AA 中遍历到的结点依次做判断，判断该结点是否可以作为子结构 BB 的根结点。

在代码中，我们写两个函数：

$isSubStructure()$，用于遍历 A 中的所有结点，并调用 helper()helper() 进行判断
$helper()$，用于判断 AA 中当前结点能否作为 BB 的根结点

$isSubStructure()$
先序遍历 AA 中所有结点
如果当前结点为 $NULL$ 或者 $B$ 为 $NULL$ ，返回 $false$。（因为题目约定，空树不是任意一个树的子结构）

$helper()$
先序遍历 $A$ 和 $B$
如果 $B = NULL$ ，说明 $B$ 已遍历完，返回 $true$
如果 $A = NULL$, $B \neq NULL$，说明 $A$ 中结点不足以构成子结构 $B$，返回 $false$
如果 $A->val \neq B->val$，不满足结点值相等条件，返回 $false$

```cpp
class Solution {
public:
    bool helper(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return B == NULL ? true : false;
        }
        if (A->val != B->val) {
            return false;
        }
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return false;
        }
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
```


## 二刷——双重DFS:  
带剪枝  
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool DFS(TreeNode* A, TreeNode* B){
        if(B==nullptr) return true;
        // B!=nullptr
        if(A==nullptr) return false;
        // B!=nullptr && A!=nullptr
        if(A->val!=B->val) return false;
        bool left = DFS(A->left, B->left);
        if(!left) return false;
        bool right = DFS(A->right, B->right);
        if(!right) return false;
        return true;
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr) return false;
        if(A==nullptr) return false;
        bool isSub = false;
        if(A->val==B->val) isSub = DFS(A, B);
        if(isSub) return true;
        isSub = isSubStructure(A->left, B);
        if(isSub) return true;
        return isSubStructure(A->right, B);
    }
};
```