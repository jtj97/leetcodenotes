# 剑指Offer06. 从尾到头打印链表:
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)    
**题目描述：**  
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。  
**示例：**  
```
输入：head = [1,3,2]
输出：[2,3,1]
```

## 自解：
思路：遍历链表得出长度后,resize数组，再遍历链表填入值。
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int i=0;
        ListNode* ptr = head;
        while(ptr != NULL){
            ptr = ptr->next;
            i++;
        }
        ptr = head;
        vector<int> result;
        result.resize(i);
        for(i; i>0 && ptr!=NULL; i--){
            result[i-1] = ptr->val;
            ptr = ptr->next;
        }
        return  result;
    }
};
```

## 更优解：
思路：栈。栈的特点是后进先出，即最后压入栈的元素最先弹出。考虑到栈的这一特点，使用栈将链表元素顺序倒置。从链表的头节点开始，依次将每个节点压入栈内，然后依次弹出栈内的元素并存储到数组中。
```cpp
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        stack<int> st;
        while(head){// push
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()){ // pop
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```