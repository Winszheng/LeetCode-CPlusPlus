/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record, ans;
        for(int n : nums1)record.insert(n);

        for(int n : nums2){
            if(record.find(n) != record.end())ans.insert(n);
        }

        vector<int> re;

        for(int n : ans)re.push_back(n);    // 我个人觉得这种语法糖比写迭代器省事多了...

        return re;
    }
};
// @lc code=end

