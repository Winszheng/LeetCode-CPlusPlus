/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
// 本质上是查是否存在——用set，维护一个最大为数组大小的滑动窗口
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record;
        for(int n : nums){
            if(record.find(n) != record.end())return true;
            record.insert(n);
        }
        return false;
    }
};
// @lc code=end

