/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

// 两个问题：
// 1.忽略了栈空时调用stack的top会段错误
// 2.运行时间太慢，仅beat 33.83%的submissions，
// 基本上这个版本是在把元素在两个栈中倒来倒去

// 如何改良：
// 队列特点：先进先出；栈特点：先进后出
// 本质上的差别是操作的位置不一样


#include<stack>
using namespace std;

class MyQueue {
    stack<int> a, b;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 问题在于这个函数
        // 队头在b栈顶时
        int re;
        if(a.size()==0){
            re = b.top();
            b.pop();
            return re;
        }
        // 队头在a栈尾时
        while(a.size()!=1){
            b.push(a.top());
            a.pop();
        }
        re = a.top();
        a.pop();
        return re;
    }
    
    /** Get the front element. */
    int peek() {    // 查队头
        // while(a.size()!=1){
        //     b.push(a.top());
        //     a.pop();
        // }
        // return a.top();
        
        int re;
        if(a.size()==0){
            re = b.top();
            return re;
        }
        // 队头在a栈尾时
        while(a.size()!=1){
            b.push(a.top());
            a.pop();
        }
        re = a.top();
        return re;
        // 傻逼行为：这样会把东西从队头加到队尾，因为不是双端队列
        // int re = pop();
        // push(re);
        // return re;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty() && b.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

