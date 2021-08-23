/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include<stack>
#include<iostream>
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

int main(){
    MyQueue q;
    // test2
    q.push(1);
    q.push(2);
    q.pop();
    q.peek();
    q.pop();
    q.empty();

    // test1
    // q.push(1);
    // q.push(2);q.push(3);q.push(4);
    // q.pop();
    // q.push(5);
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
}