### [剑指 Offer II 053\. 二叉搜索树中的中序后继](https://leetcode-cn.com/problems/P5rCT8/)

Difficulty: **中等**


给定一棵二叉搜索树和其中的一个节点 `p` ，找到该节点在树中的中序后继。如果节点没有中序后继，请返回 `null` 。

节点 `p` 的后继是值比 `p.val` 大的节点中键值最小的节点，即按中序遍历的顺序节点 `p` 的下一个节点。

**示例 1：**

![](https://assets.leetcode.com/uploads/2019/01/23/285_example_1.PNG)

```
输入：root = [2,1,3], p = 1
输出：2
解释：这里 1 的中序后继是 2。请注意 p 和返回值都应是 TreeNode 类型。
```

**示例 2：**

![](https://assets.leetcode.com/uploads/2019/01/23/285_example_2.PNG)

```
输入：root = [5,3,6,2,4,null,null,1], p = 6
输出：null
解释：因为给出的节点没有中序后继，所以答案就返回 null 了。
```

**提示：**

*   树中节点的数目在范围 `[1, 10<sup>4</sup>]` 内。
*   `-10<sup>5</sup> <= Node.val <= 10<sup>5</sup>`
*   树中各节点的值均保证唯一。

注意：本题与主站 285 题相同： 


#### Solution

使用迭代方式中序遍历。  
目标节点存在右子节点时，则下一个节点为目标节点右子节点的最左子节点。  
不存在右子节点时，则为其父节点（根据栈是否为空判断）

```cpp
​/**
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode *ptr = root;
        while(ptr){
            stk.push(ptr);
            ptr = ptr->left;
        }
        while(!stk.empty()){
            TreeNode *view = stk.top();
            stk.pop();
            if(view==p){
                if(view->right){
                     ptr = view->right;
                     while(ptr->left) ptr = ptr->left;
                     return ptr;
                } else if(!stk.empty()){
                    return stk.top();
                } else {
                    return nullptr;
                }
            } else if (view->right) {
                ptr = view->right;
                while(ptr){
                    stk.push(ptr);
                    ptr = ptr->left;
                }
            }
        }
        return nullptr;
    }
};
```