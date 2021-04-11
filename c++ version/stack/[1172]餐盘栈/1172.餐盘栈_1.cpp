/*
 * @lc app=leetcode.cn id=1172 lang=cpp
 *
 * [1172] 餐盘栈
 */

// 把多个栈看成是首尾相连的 —— 可以用vector<int>模拟无限个栈
// 用1个vector标志每个栈有几个元素
// 用一个“指针”标志下次push的地方
// 管理主a辅b

// 18/19 cases passed
// 这tm都超时...

#include <vector>
#include <iostream>
using namespace std;

// 1.return不小心没写在大括号里面
class DinnerPlates {
    vector<int> a;
    vector<int> b;
    int cap;
    int p;
    int size;
public:
    DinnerPlates(int capacity) {
        p = 0, size = 0;
        cap = capacity;
        b.push_back(0);
    }
    
    void push(int val) {
        size++;
        int index = p*cap + b[p];
        if(index >= a.size()) a.push_back(val);
        else {
            a[index] = val;
            // cout<<"a["<<index<<"]="<<val<<endl;
        }
        b[p]++;
        // cout<<"b["<<p<<"]="<<b[p]<<endl;
        if(b[p] == cap){
            int i;
            for(i = p+1; i<b.size(); i++){
                if(b[i] < cap){
                    p=i;
                    return;
                }
            }
            b.push_back(0);
            p = b.size() - 1;
        }
    }
    
    int pop() {
        if(size == 0) return -1;  // 空
        int index = b.size() - 1;
        while(b[index] == 0)index--;

        // cout<<"b["<<index<<"]="<<b[index]<<endl;
        
        int re = a[index*cap + b[index] - 1];
        b[index]--;
        if(index < p) p = index;

        // int re = a.back();
        a.pop_back();
        
        size--;
        
        return re;
    }
    
    int popAtStack(int index) {
        if(index<0 || index>=b.size() || b[index]==0)return -1;
        b[index]--;
        if(index < p) p =index;
        int re = a[index*cap + b[index]];
        
        size--;
        
        return re;
    }
};

