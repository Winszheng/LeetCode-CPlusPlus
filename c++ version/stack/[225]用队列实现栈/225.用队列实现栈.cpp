/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start

// 其实只用一个队列实现栈也没毛病 —— 利用的是stack元素的想丢关系
// 反正用两个复杂度也不会更低
#include <queue>
using namespace std;
class MyStack {
    queue<int> a;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = a.size();
        a.push(x);
        for(int i=0;i<n;i++){
            a.push(a.front());
            a.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = a.front();
        a.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return a.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

