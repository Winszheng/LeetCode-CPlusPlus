#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
// 固定大小的滑动窗口+哈希表
// 由 |a - b| <= t
// ==> -t <= a-b <= t
// ==> a-t <= b <= a+t
// 把问题转换成，在滑动窗口中，寻找一个符合条件的b值

// long 和long long什么区别？
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
         set<long long> s;
         for(int i=0; i<nums.size(); i++){
            //  因为set是有序的，所以可以直接用lower_bound
             auto pos = s.lower_bound((long long)(nums[i]) - t);
             if(pos != s.end() && *pos <= (long long)(nums[i]) + t)return true;
             s.insert(nums[i]);
             if(s.size() > k)s.erase(nums[i-k]);
         }
         return false;
    }
};

