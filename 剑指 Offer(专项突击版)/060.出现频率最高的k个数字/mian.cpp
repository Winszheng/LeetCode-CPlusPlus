#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 考察出现频率最高的前k个数字
// 堆里要放的是键值对-(key, 频率)
// 顶部是频率最小的

// 时空效率很理想

class Solution {
public:
    struct cmp{ // 构造小顶堆
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        unordered_map<int, int> re;
        vector<int> ret;
        for(int n : nums){
            re[n]++;
        }
        for(auto o : re){
            if(q.size() < k)q.push(o);
            else if(o.second > q.top().second){
                q.pop();
                q.push(o);
            }
        }
        while(!q.empty()){
            auto o = q.top(); q.pop();
            ret.push_back(o.first);
        }
        return ret;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution s;
    auto o = s.topKFrequent(nums, 2);
    for(int i : o)cout<<i<<" ";
    cout<<endl;
}