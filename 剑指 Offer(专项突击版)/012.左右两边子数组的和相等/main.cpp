#include <vector>
using namespace std;
// 从左往右搜索、从右往左搜索，找两遍前缀，再一次搜索，找结果
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n), b(n);
        a[0] = nums[0], b[n-1]=nums[n-1];
        for(int i=1;i<n;i++)a[i] = a[i-1]+nums[i];
        for(int i=n-2;i>=0;i--)b[i] = nums[i]+b[i+1];
        if(b[1] == 0)return 0;
        for(int i=1;i<n-1;i++){
            if(a[i-1] == b[i+1])return i;
        }
        if(a[n-2]==0)return n-1;
        return -1; 
    }
};