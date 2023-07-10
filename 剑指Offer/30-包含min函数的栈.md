# 剑指Offer30. 包含min函数的栈:  
**题目地址：**[LeetCode](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)  
**题目描述：**   
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。  
**示例:**  
```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```

## 自解：
设计一个含有上一个最小值的结构体Node;
```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    struct Node{
        int val;
        int lastmin;
        Node() : val(0), lastmin(0){}
        Node(int x, int y) : val(x), lastmin(y){}
    };
    stack<Node> S;
    int lastmin;
    MinStack() {
    }
    
    void push(int x) {
        if(S.empty()){
            S.push(Node(x, x));
            lastmin = x;
        } else if(x<=lastmin) {
            S.push(Node(x,x));
            lastmin = x;
        } else if(x>lastmin) {
            S.push(Node(x, lastmin));
        }
    }
    
    void pop() {
        if(S.top().val==lastmin){
            S.pop();
            if(!S.empty()){
                lastmin = S.top().lastmin;
            }
        } else{
            S.pop();
        }
    }
    
    int top() {
        return S.top().val;
    }
    
    int min() {
        return S.top().lastmin;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
 ```

## 辅助栈：  
![](./Pic/30.png)  
Java版本 
[链接link](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/solution/mian-shi-ti-30-bao-han-minhan-shu-de-zhan-fu-zhu-z/)
 
```java
class MinStack {
    Stack<Integer> A, B;
    public MinStack() {
        A = new Stack<>();
        B = new Stack<>();
    }
    public void push(int x) {
        A.add(x);
        if(B.empty() || B.peek() >= x)
            B.add(x);
    }
    public void pop() {
        if(A.pop().equals(B.peek()))
            B.pop();
    }
    public int top() {
        return A.peek();
    }
    public int min() {
        return B.peek();
    }
}
```