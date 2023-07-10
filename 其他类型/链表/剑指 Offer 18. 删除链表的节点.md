# 剑指Offer18. 删除链表的节点:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/)  

## 解答:
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==nullptr){
            return head;
        }
        ListNode *pre = head;
        if(pre->val==val){
            return pre->next;
        }
        ListNode *cur=nullptr;
        while(pre->next != nullptr){
            cur = pre->next;
            if(cur->val==val){
                pre->next = cur->next;
                cur->next = nullptr;
                break;
            }
            pre = pre->next;
        }
        return head;
    }
};
```

二刷：  
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while(cur!=nullptr){
            if(cur->val==val){
                pre->next = cur->next;
                cur->next = nullptr;
                break;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
```