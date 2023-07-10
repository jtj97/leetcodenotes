# 剑指Offer27. 二叉树的镜像:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)    
**题目描述：**  

请完成一个函数，输入一个二叉树，该函数输出它的镜像。 
**示例：**  
```
例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

## 自解——递归：
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
    TreeNode* mirrorTree(TreeNode* root) {
        exchangeLR(root);
        return root;
    }
    void exchangeLR(TreeNode* root){
        if(root == NULL){
            return;
        }
        TreeNode *rootTemp = root->left;
        root->left = root->right;
        root->right = rootTemp;
        exchangeLR(root->left);
        exchangeLR(root->right);
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
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        TreeNode *head = new TreeNode(root->val);
        head->left = mirrorTree(root->right);
        head->right = mirrorTree(root->left);
        return head;
    }
};
```