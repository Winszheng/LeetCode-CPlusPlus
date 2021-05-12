/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
// 维护一个n-k的最大堆
// 先把最大堆放满，然后利用最大堆的特性，每一次都选一个频率大的放到结果数组
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> fre;
      for(int n : nums)fre[n]++;
      priority_queue<pair<int, int>> q; //fre value
      vector<int> re;
      for(auto it : fre){
          if(q.size() == fre.size()-k){
              if(q.size() == 0){
                  re.push_back(it.first);
                  continue;
              }
              auto temp = q.top();
              cout<<temp.second;
              if(it.second > temp.first)re.push_back(it.first);
              else{
                  q.pop();
                  re.push_back(temp.second);
                  q.push(make_pair(it.second, it.first));
              }
          }else q.push(make_pair(it.second, it.first));
      }
     
      return re;
    }
};
// @lc code=end