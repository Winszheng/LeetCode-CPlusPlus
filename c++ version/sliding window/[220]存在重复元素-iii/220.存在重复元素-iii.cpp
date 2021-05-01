/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
// 把问题转换成|x-y|<t ==> x-t < y < x + t
// 即，每次遇到一个元素x，都找有没有符合要求的y
// 这样需要元素有序——用set
// 需要一个固定大小的滑动窗口
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;  // 64位整型，int是32位整型
        for(int i = 0; i< nums.size(); i++){
            long long n = nums[i];
            if(record.lower_bound(n - (long long)t) != record.end() && 
            *record.lower_bound(n - (long long)t) <= n + (long long)t)
            return true;

            record.insert(n);
            if(record.size() == k+1)record.erase(nums[i-k]);
        }
        return false;
    }
};
// @lc code=end