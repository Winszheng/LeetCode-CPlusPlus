/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        for(int n : nums1)record[n]++;
        vector<int> re;
        for(int n : nums2){
            if(record[n] > 0){
                re.push_back(n);
                record[n]--;
            }
        }
        return re;
    }
};
// @lc code=end

