/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
// 删除有序数组中的重复项，并返回新数组的长度
// 空间复杂度要求O(1)
// 和27、283思路本质一直，但是写法不能直接套
// 所以选用快慢指针(关键对于双指针的理解)==
// define：
// slow - 有效序列末尾的后一个元素
// fast - 待检查的第一个元素
// 所以真正需要比较的，是下标为slow-1的元素和fast指向的元素
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // slow表有效序列末尾的后一个元素
        // fast表当前操作元素
        int slow = 1, fast = 1;
        
        if(nums.size() == 0)return 0;
        while(fast < nums.size()){
            if(nums[fast] != nums[slow - 1]){
                nums[slow] = nums[fast];
                    slow++;
            }
            fast++;
        }
        return slow;

    }
};
// @lc code=end

