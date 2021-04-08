/*
 * @lc app=leetcode.cn id=1172 lang=cpp
 *
 * [1172] 餐盘栈
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

// 17/19 超出时间限制
// 折腾了两个小时
// 然而并没有什么用
// 这个解法本身有问题, 时间上效率不行
// 需要改良

class DinnerPlates {
    int ca;
    vector<stack<int>> a;
public:
    DinnerPlates(int capacity) {
        ca = capacity;
        stack<int> b;
        a.push_back(b);
    }
    
    void push(int val) {    // 因为不删除元素所以这里也有问题
        for(int i=0; i<a.size();i++){
            if(a[i].size() == ca){
                continue;
            }else{
                a[i].push(val);
                return;
            }
        }
        stack<int> b;
        a.push_back(b);
        a[a.size()-1].push(val);
    }
    
    int pop() {
        // 用这个判断的前提是，会删掉vector的元素，因为不删，所以没用了
        // if(a.size() == 0) return -1;

        int index = a.size() - 1;
        while(index >=0 && a[index].size() == 0)index--;
        if(index < 0 ) return -1;
        
        int x = a[index].top();
        a[index].pop();
        // if(a[a.size()-1].size() == 0)a.pop_back();
        return x;
    }
    
    int popAtStack(int index) {
        if(index<0 || index >= a.size() || a[index].size() == 0 ) {
            return -1;
        }
        int x = a[index].top();
        
        a[index].pop();
        
        return x;
    }   
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end

