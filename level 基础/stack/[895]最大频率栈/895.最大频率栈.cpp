/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start

// 思路类似于找栈中最值，但是因为多了一个元素(频率最高中最靠近栈顶)
// 所以不能简单地用两个栈实现
// 用映射关联起来
// 相当于建立3列映射 例如
// 元素 频率 栈层
// a    d   g
// b    e   h
// c    f   i

#include <unordered_map>
#include <stack>
#include <iostream>
using namespace std;
class FreqStack {
    unordered_map<int, int> a;
    unordered_map<int, stack<int>> b;
    int mx;
public:
    FreqStack() {
        mx = 0;
    }
    
    void push(int val) {
        a[val]++;
        b[a[val]].push(val);
        mx = max(mx, a[val]);
    }
    
    int pop() {
        int x = b[mx].top();
        b[mx].pop();
        a[x]--;
        while(b[mx].empty() && mx>0)mx--;
        // 如果不限制键的范围，能搞出一堆负数key，显然错误
        // 别人的题解用if只是凑巧也能做这题罢了
        return x;
    }
};
// mx=-104071
// mx=-104072
// mx=-104073
// mx=-104074
// mx=-104075
// mx=-104076
// mx=-104077
// mx=-104078

