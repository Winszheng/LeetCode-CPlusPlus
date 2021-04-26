/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// 因为数组无序，所以不能用双指针
// 但是可以用map很轻松地做出来
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> record;   // 存数字本身及其坐标
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

