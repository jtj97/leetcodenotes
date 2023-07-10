# 剑指Offer09. 用两个栈实现队列:
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)    
**题目描述：**  
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 `appendTail` 和 `deleteHead` ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，`deleteHead` 操作返回 `-1` )
**示例：**  
```
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]




输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```
```
输入：

["CQueue","appendTail","deleteHead","deleteHead"] 
这一行表示每一行代码的操作

[[],[3],[],[]]
这个表示每一行代码操作所需要的参数

举例：
CQueue 表示新建一个CQueue对象，对应的所需参数为[]，即此操作不需要参数。
appendTail 表示执行一个appendTail()操作，对应要被操作的元素为3。
deleteHead 表示执行一个deleteHead操作，对应的所需参数为[]，即此操作不需要参数。
deleteHead 表示执行一个deleteHead操作，对应的所需参数为[]，即此操作不需要参数。

以上的输入其实是一个代码执行的步骤描述与其对应所需参数。

即两个纬度：
1、操作描述
2、此次操作所需参数
3、操作描述与操作所需参数是通过默认顺序一一对应的。
```

## 自解:
```cpp
class CQueue {
public:
    stack<int> a; //栈顶为尾元素
    stack<int> b; //栈顶为首元素
    CQueue() {
    }
    
    void appendTail(int value) {
        if(b.empty()){
            a.push(value);
        }  else {
            while(!b.empty()){
                a.push(b.top());
                b.pop();
            }
            a.push(value);
        }
    }
    
    int deleteHead() {
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        if(b.empty()){
            return -1;
        } else {
            int delValue = b.top();
            b.pop();
            return delValue;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

## 解：
加入队尾 `appendTail()` 函数： 将数字 `val` 加入栈 `A` 即可。
删除队首 `deleteHead()` 函数： 有以下三种情况。
* 当栈 `B` 不为空： B中仍有已完成倒序的元素，因此直接返回 `B` 的栈顶元素。
* 否则，当 `A` 为空： 即两个栈都为空，无元素，因此返回 `-1`  。
* 否则： 将栈 `A` 元素全部转移至栈 `B` 中，实现元素倒序，并返回栈 `B` 的栈顶元素。
```cpp

class CQueue {
    stack<int> stack1,stack2;
public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        // 如果第二个栈为空
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        } 
        if (stack2.empty()) {
            return -1;
        } else {
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
```


#### 二刷  
```cpp
class CQueue {
private:
    stack<int> head;
    stack<int> tail;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        tail.emplace(value);
    }
    
    int deleteHead() {
        if(!head.empty()){
            int temp = head.top();
            head.pop();
            return temp;
        }
        while(!tail.empty()){
            int temp = tail.top();
            head.emplace(temp);
            tail.pop();
        }
        if(!head.empty()){
            int temp = head.top();
            head.pop();
            return temp;
        } else {
            return -1;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```