/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include<stack>
using namespace std;

// 要点在于，理解只要有两个栈，就能轻松实现数组的反转
// 与初版相比，减少了很多次pop操作，提高了运行时间
// runtime beats 100%
// memory usage beats 97.77%

class MyQueue {
    stack<int> a, b;
    void in2out(){
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
       a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
       if(b.empty()){
           in2out();
       }
       int x = b.top();
       b.pop();
       return x;
    }
    
    /** Get the front element. */
    int peek() {
      if(b.empty()){
          in2out();
      }
      return b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return a.empty() && b. empty();
    }
};

// @lc code=end
