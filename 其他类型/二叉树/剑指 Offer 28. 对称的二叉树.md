# 剑指Offer28. 对称的二叉树:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/)    
**题目描述：**  
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。  
**示例：**  
```
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
```

## 递归:  
判断左节点的左子节点和右节点的右子节点；左节点的右子节点和右节点的左子节点。递归
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
public:
    bool isSymmetric(TreeNode* root) {
        return root==nullptr ? true: help(root->left, root->right);
    }
    bool help(TreeNode *left, TreeNode *right){
        if(left==nullptr && right==nullptr){
            return true;
        } else if (left==nullptr || right==nullptr || left->val!=right->val){
            return false;
        }
        return help(left->left, right->right) && help(left->right, right->left);
    }
};
```

## 二刷:  
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
    bool helper(TreeNode* A, TreeNode* B){
        if(A==nullptr && B==nullptr) return true;
        else if (A==nullptr || B==nullptr) return false;
        return A->val==B->val && helper(A->left, B->right) && helper(A->right, B->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return helper(root->left, root->right);
    }
};
```