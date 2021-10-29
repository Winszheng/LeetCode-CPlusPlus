#include <vector>
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

// 困难题 - 只能做两次股票交易
// 第i天过后，只有五种状态：0操作、一次买入、一次卖出、二次买入、二次卖出
// 思路：每天过去后，记录当天每种状态的最优解(最大利润)
// 注：一天当中同时买入卖出，相当于没有操作
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 第1、2次买入 第1、2次卖出
       int a1=INT_MIN, a2=INT_MIN, b1=0, b2=0;
       for(int p : prices){
           // 第一次买入的最优利润
           a1 = max(a1, -p);    
           // 第一次卖出的最优利润
           // 如果既买又卖，相当于空操作；否则，相当于试图更新
           b1 = max(b1, a1 + p);
           // 第二次买入 
           a2 = max(a2, b1-p);
           // 第二次卖出
           b2 = max(b2, a2+p);
       }
       return max(b1, b2);
    }
};

int main(){
    vector<int> p1{3,3,5,0,0,3,1,5};
    vector<int> p2{1, 2, 3, 4, 5};
    Solution s;
    s.maxProfit(p2);
}