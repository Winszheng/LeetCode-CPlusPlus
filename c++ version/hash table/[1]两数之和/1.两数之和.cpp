/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// 因为数组无序，所以不能用双指针
// 但是可以用map很轻松地做出来

// map
// Your runtime beats 25.06 % of cpp submissions
// Your memory usage beats 60.87 % of cpp submissions (8.7 MB)

// unordered_map
// Your runtime beats 55.38 % of cpp submissions
// Your memory usage beats 84.09 % of cpp submissions (8.6 MB)

// 不需要排序的时候，unordered_map的效率比map显著有提高
// 时空复杂度都是O(n)
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;   // 存数字本身及其坐标
        for(int i = 0; i<nums.size();i++){
            if(record.find(target - nums[i]) == record.end()){
                record[nums[i]] = i;
            }else{
                return {i, record[target - nums[i]]};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

