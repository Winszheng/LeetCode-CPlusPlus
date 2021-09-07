#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 2.排序，因为排序后同样大小的数字一定是连续的
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i+1<n && nums[i]==nums[i+1])i+=2;
            else return nums[i];
        }
        return nums[0]; // 必须要有返回值
    }
};

// 抽象后：