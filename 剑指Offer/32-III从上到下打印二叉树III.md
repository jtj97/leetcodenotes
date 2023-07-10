# 剑指Offer32III.  从上到下打印二叉树 III：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/)  
**题目描述：**  
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。  
**示例**
```
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]

```

## 解——BFS:
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }
        q.emplace(root);
        while(!q.empty()){
            vector<int> temp;
            int len = q.size();
            for(int i=0; i<len; i++){
                temp.emplace_back(q.front()->val);
                if(q.front()->left != nullptr){
                    q.emplace(q.front()->left);
                }
                if(q.front()->right != nullptr){
                    q.emplace(q.front()->right);
                }
                q.pop();
            }
            result.emplace_back(temp);
        }
        int len = result.size();
        for(int i=1; i<len; i+=2){
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};
```

改进：将翻转逻辑放在循环中
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> currs;
            for (int i = q.size() - 1; i >= 0; --i)
            {
                TreeNode* curr = q.front();
                q.pop();
                currs.push_back(curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            // 当前res.size()为偶数时无需翻转，否则要翻转
            if (res.size() & 1)
            {
                reverse(currs.begin(), currs.end());
            }
            res.push_back(currs);
        }

        return res;
    }
};
```