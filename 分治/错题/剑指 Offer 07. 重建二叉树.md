# 剑指Offer07. 重建二叉树：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)  
**题目描述：**  
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
**示例:**  
```
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
```

## 递归:  
分治思想，
前序遍历性质： 节点按照 `[ 根节点 | 左子树 | 右子树 ]` 排序。
中序遍历性质： 节点按照 `[ 左子树 | 根节点 | 右子树 ]` 排序。

前序遍历的首元素 为 树的根节点 `node` 的值。
在中序遍历中搜索根节点 `node` 的索引 ，可将 中序遍历 划分为 `[ 左子树 | 根节点 | 右子树 ]` 。
根据中序遍历中的左 / 右子树的节点数量，可将 前序遍历 划分为 `[ 根节点 | 左子树 | 右子树 ]` 。


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preO = preorder;
        for(int i=0; i<inorder.size(); i++){
            dic[inorder[i]] = i;
        }
        return recur(0, 0, inorder.size()-1);
    }
private:
    vector<int> preO;
    unordered_map<int, int> dic;
    /*
    * @param root 先序遍历的索引
    * @param left 中序遍历的索引
    * @param right 中序遍历的索引
    */
    TreeNode* recur(int root, int left, int right){
        if(left>right){
            return nullptr;
        }
        TreeNode *node = new TreeNode(preO[root]);//建立新的根节点
        int posIn = dic[preO[root]];//posIn为中序遍历中根节点位置
        node->left = recur(root + 1, left, posIn-1);
        node->right = recur(root + posIn - left + 1, posIn+1, right);//posIn-left为左子树长度
        return node;
    }
};
```