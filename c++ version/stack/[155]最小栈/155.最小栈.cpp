/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start

// 初版思路：
// 设置一个min，每次入栈都和栈顶元素比较，getMin时直接返回min 
// —— 本质上是设置flag的思路，这样不好

// 改良思路：
// 由于栈先进后出的性质，本质上只要知道栈顶，底下的元素都是固定的
// 即使混搭了pop的操作，这个性质本质上也没有发生改变
// 因此，只要设置一个辅助栈，和主栈始终同步，每一层都保存着主栈对应层的min即可
// 其他的“最值”等特殊值，也可以这样做

// output：
// 用3元运算符时，时间空间都只有20%+
// 用标准库min函数，时间83%空间8%
// 看了一眼大家的思路大同小异，算了
// 还是用库函数⑧

#include <stack>
using namespace std;
class MinStack {
    stack<int> a, b;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val) {
        a.push(val);
        if(b.empty()){
            b.push(val);
        }else{  // c++标准库中头文件有min和max的宏
            b.push(min(val, b.top()));
        }
    }
    
    void pop() {
        a.pop();
        b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

