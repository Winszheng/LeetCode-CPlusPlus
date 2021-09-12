#include <vector>
#include <string>
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

// 把时间转成分钟
// 排序
// 按相邻不断获取最小值，最大最小值需要特殊处理

class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> time;
        for(int i=0;i<t.size();i++){
            int tt = stoi(t[i].substr(0, 2))*60 + stoi(t[i].substr(3, 2));
            time.push_back(tt);
        }
        sort(time.begin(), time.end());
        int n = time.size();
        int re = 24*60 - time[n-1]+time[0];
        for(int i=1;i<n;i++){
            re = min(re, time[i] - time[i-1]);
        }
        return re;

    }
};

int main(){
    Solution s;
    vector<string> temp{"23:59", "00:00"};
    cout<<s.findMinDifference(temp)<<endl;
}