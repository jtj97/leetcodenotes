### [剑指 Offer 33\. 二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

Difficulty: **中等**


输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 `true`，否则返回 `false`。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

```
     5
    / \
   2   6
  / \
 1   3
```

**示例 1：**

```
输入: [1,6,3,2,5]
输出: false
```

**示例 2：**

```
输入: [1,3,2,6,5]
输出: true
```

**提示：**

1.  `数组长度 <= 1000`


#### Solution
后序遍历定义： `[ 左子树 | 右子树 | 根节点 ]`  
根据二叉搜索树性质，左子树小于根节点，右子树大于根节点。记录左子树和右子树分界。
终止条件:
`left<=right`时说明`子树节点数<=1`，直接返回`true`



```cpp
​class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size()-1);
    }
    bool helper(vector<int>& postorder, int left, int right){
        if(left>=right){
            return true;
        }
        int pos = left;
        while(postorder[pos]<postorder[right]){
            pos++;
        }
        int div = pos;
        while(postorder[pos]>postorder[right]){
            pos++;
        }
        if(pos!=right){
            return false;
        }
        return helper(postorder, left, div-1) && helper(postorder, div, right-1);
    }
};
```


二刷:  

后序遍历 [左|右|根]  
由于二叉搜索树性质可分为[<根|>根|根]三个部分。  
上面是从左到右，下面是从右到左。

```cpp
class Solution {
private:
    bool helper(vector<int>& postorder, int left, int right){
        if(left<0 || right<0 || left>=right) return true;
        //cout<<left<<" "<<right<<endl;
        int pos = right;
        while(pos>=left && postorder[pos]>=postorder[right]) --pos;
        int rightEdge = pos + 1;
        while(pos>=left && postorder[pos]<postorder[right]) --pos;
        if(pos!=left-1) return false;
        return helper(postorder, left, rightEdge-1) && helper(postorder, rightEdge, right-1);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()==0) return true;
        return helper(postorder, 0, postorder.size()-1);
    }
};
```