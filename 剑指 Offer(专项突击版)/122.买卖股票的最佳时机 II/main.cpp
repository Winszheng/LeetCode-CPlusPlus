#include <vector>
#include <stack>
using namespace std;

// 因为可以无限次买卖，而股票的价格走势其实可以看做锯齿图
// 那么，只要记录每一个上升段的加和即可
// 为了避免最后一个上升段被遗漏
// 在原数组补0

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s;
        int sum = 0;
        prices.push_back(0);
        for(int p : prices){
            if(s.empty() || s.top() <= p){
                s.push(p);continue;
            }
            int b = s.top();
            int a;
            while(!s.empty()){
                a = s.top(); s.pop();
            }
            sum += b-a;
            s.push(p);
        }
        
        return sum;
    }
};