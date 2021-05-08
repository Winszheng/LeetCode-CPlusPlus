/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
// 要求的是映射关系，用map
// 两件事：
// 1.c++自带的size()函数不能直接做解法，否则会溢出
// 2.c++的set和map是按键排序的
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// 典型的优先队列题
// 策略：维护一个大小为k的优先队列，底层是最小堆，思路和滑动窗口是一样的
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;    // 元素 频率
        for(int n : nums)fre[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;  // fre value
        for(auto i : fre){
            if(q.size() == k){
                auto temp = q.top();
                if(temp.first < i.second){
                    q.pop();
                    q.push(make_pair(i.second, i.first));
                }
            }else q.push(make_pair(i.second, i.first));
        }
        vector<int> re;
        while(!q.empty()){
            auto temp = q.top();
            re.push_back(temp.second);
            q.pop();
        }
        return re;
    }
};
// @lc code=end

