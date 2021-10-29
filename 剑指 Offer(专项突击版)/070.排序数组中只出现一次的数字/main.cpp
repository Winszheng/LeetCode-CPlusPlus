#include <vector>
using namespace std;

// 按规律，每个偶数下标的数字都和它右侧的数字一致，直到遇到第一个破坏规律的数字
// 因此，每次探索的都应该是偶数下标的数字

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 劳资就是不想用二分查找！！！
        int l=0, r=nums.size()/2;
        while(l <= r){
            int mid = (l+r)/2;
            int i = mid*2;
            if(i<nums.size()-1 && nums[i]!=nums[i+1]){
                if(i==0 || nums[i]!=nums[i-1])return nums[i];
                r = mid-1;
            }else l = mid+1;
        }
        return nums[nums.size()-1];
    }
};