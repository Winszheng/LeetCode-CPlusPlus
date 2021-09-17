#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>   // abs函数
using namespace std;

// 经典的栈问题，星星的大小不可能是0
// 什么时候会发生碰撞？
// 只有栈顶为正，且探测为负的时候才会发生碰撞
// - 1.当栈不空，栈顶大于零且栈顶绝对值小于探测值，不断出栈
// - 2.若栈空or栈顶为负，入栈
// - 3.若栈顶绝对值相同，出栈；若栈顶绝对值更大，下一个

// 时间效率很高，但内存效率很一般

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int x : asteroids){
            if(x > 0){
                s.push(x);continue;
            }
            while(!s.empty() && s.top()>0 && s.top() < abs(x))s.pop();
            
            if(s.empty() || s.top()<0){
                s.push(x);continue;
            }

            if(s.top() > abs(x))continue;
            if(s.top() == abs(x))s.pop();
        }
        vector<int> re;
        while(!s.empty()){
            re.push_back(s.top());s.pop();
        }
        reverse(re.begin(), re.end());
        return re;
    }
};

