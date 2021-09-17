// 把0转换成-1
// 求当和为0的最长一段
// 前缀和，差值就是需要的长度

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> temp;temp[0]=-1;// 初始和为0的下标是-1
        int t=0, n=nums.size(), re=0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0)t -= 1;
            else t += 1;
            if(temp.find(t) != temp.end()){ // 搜索有没有这个key
                re = max(re, i-temp[t]);    
            }else temp[t] = i;
        }
        return re;
    }
};