#include <vector>
using namespace std;

// 因为是有序列表，所以显然是二分查找
// 1.直接找到了
// 2.插入开头-mid==0也找不到
// 3.插入结尾-mid==n-1也找不到

// 时间效率很高，但是不知为什么，内存效率很低！
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        if(target < nums[0])return 0;
        if(target > nums[r])return r+1;
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target)return mid;
            if(target>nums[mid]){
                if(target<nums[mid+1])return mid+1;
                else l=mid+1;
            }else r=mid-1;
        }
        return mid; // just占位
    }
};