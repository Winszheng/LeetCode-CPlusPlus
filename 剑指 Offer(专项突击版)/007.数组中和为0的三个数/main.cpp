#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 三数为零
// 1.暴力解法：三重循环，超时
// 2.双指针：二重循环
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;

            int l=i+1, r=n-1;
            while(l<r){

                int t = nums[i]+nums[l]+nums[r];
                // cout<<t<<",";
                if(t > 0)r--;
                else if(t < 0)l++;
                else{
                    re.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l] == nums[l+1])l++;  // key
                    l++, r--;
                }
            }
        }
        return re;
    }
};

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    Solution s;s.threeSum(nums);
}