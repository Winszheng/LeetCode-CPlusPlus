#include <vector>
using namespace std;
// 单调栈: 用于求满足第一个xx条件的yy
// 通常，不满足xx条件的入栈，每当遇到满足条件的就出栈并计算

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> re(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                re[s.top()] = i - s.top(); s.pop();
            }     
            s.push(i);
        }
        return re;
    }
};