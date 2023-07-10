# 剑指Offer32II. 从上到下打印二叉树II：  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)    
**题目描述：**  
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
**示例：**  
```
例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
```

## 自解：  
利用Hash表储存层数
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
        vector<vector<int>> result;
        unordered_map<TreeNode*, int> mp;
        stack<TreeNode*> S;
        if(root==nullptr){
            return result;
        }
        S.push(root);
        TreeNode *ptr=nullptr;
        mp.insert(make_pair(root, 0));
        while(!S.empty()){
            ptr = S.top();
            S.pop();
            Travel(ptr, result, mp[ptr]);
            if(ptr->right!=nullptr){
                S.push(ptr->right);
                mp.insert(make_pair(ptr->right, mp[ptr]+1));
            }
            if(ptr->left!=nullptr){
                S.push(ptr->left);
                mp.insert(make_pair(ptr->left, mp[ptr]+1));
            }
        }
        return result;
    }
    void Travel(TreeNode* root, vector<vector<int>> &result, int depth){
        if(root==nullptr){
            return;
        }
        if(result.size()<depth+1){
            vector<int> temp;
            temp.emplace_back(root->val);
            result.emplace_back(temp);
        } else {
            result[depth].emplace_back(root->val);
        }
        return;
    }
};
```

## BFS:
按层打印： 题目要求的二叉树的 **从上至下** 打印（即按层打印），又称为二叉树的 **广度优先搜索**（BFS）。BFS 通常借助 **队列** 的先入先出特性来实现。  
算法：
- 特例处理： 当根节点为空，则返回空列表 `[]` ；
- 初始化： 打印结果列表 `res = []` ，包含根节点的队列 `queue = [root]` ；
- BFS 循环： 当队列 `queue` 为空时跳出；
    - 新建一个临时列表 `tmp` ，用于存储当前层打印结果；
    - 当前层打印循环： 循环次数为当前层节点数（即队列 `queue` 长度）；
        - 出队： 队首元素出队，记为 `node`；
        - 打印： 将 `node.val` 添加至 tmp 尾部；
        - 添加子节点： 若 `node` 的左（右）子节点不为空，则将左（右）子节点加入队列 `queue` ；
    - 将当前层结果 `tmp` 添加入 `res` 。
- 返回值： 返回打印结果列表 `res` 即可。
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
        return result;
    }
};
```