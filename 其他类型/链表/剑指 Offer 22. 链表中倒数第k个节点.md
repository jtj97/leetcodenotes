# 剑指Offer22. 链表中倒数第k个节点:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)  
**题目描述：**  
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。  
例如，一个链表有 `6` 个节点，从头节点开始，它们的值依次是 `1、2、3、4、5、6` 。这个链表的倒数第 `3` 个节点是值为 `4` 的节点。  
**示例：**  
```
给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
```

## 自解：
双指针：  
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* tail=head;
        for(int i=0; i<k; i++){
            tail = tail->next;
        }
        while(tail != NULL){
            head = head->next;
            tail = tail->next;
        }
        return head;
    }
};
```
**NOTE**  
本题未考虑越界情况，如考虑越界则有如下情况：
1.head为空指针；  
2.k大于链表的长度；  
3.输入的参数k为0。  
考虑越界情况代码:
```cpp
if(head == NULL || k == 0){
    return NULL;
} //考虑特殊情况1、3
for(int i = 0;i<k;i++){
    if(former == NULL && i<k){
        return NULL;
    } //考虑特殊情况2
    ormer = former->next;
        }
        ```