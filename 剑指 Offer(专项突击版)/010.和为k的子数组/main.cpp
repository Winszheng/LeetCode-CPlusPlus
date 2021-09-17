// 前缀和 O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> re;re[0]=1;
        int n=nums.size(), t=0, ret=0;
        for(int i=0;i<n;i++){
            t += nums[i];
            if(re.find(t-k) != re.end())ret += re[t-k];
            re[t]++;
        }
        return ret;
    }
};