/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
// 带有重复元素的全排列
// 如果照搬之前的思路，必然会出现重复
// 盲猜重复元素的出现，是为了给你做剪枝

// 这道题比46题多了一个条件，就是元素可以重复，那么，只要保证相同的元素中只有一个可以出现在特定的位置就可以了
// 以第一个位置作为锚点，例如如果重复元素是1，那么当第一个1出现在锚点之后，其他元素1都不要再做考虑，即可
// 因为元素重复，使用的数据结构从set变成map，为了记录频率，不过本质是一样的
class Solution {
    void resolve(vector<vector<int>>& re, unordered_map<int, int> sett, vector<int> temp, int n){
        temp.push_back(n);sett[n]--;
        if(sett[n] == 0)sett.erase(n);
        if(sett.empty()){
            re.push_back(temp);
            return;
        }
        for(auto t : sett){
            resolve(re, sett, temp, t.first);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> sett;
        for(int n : nums)sett[n]++;
        int pre = 11;
        for(int n : nums){
            if(n == pre)continue;
            resolve(re, sett, {}, n);
            pre = n;
        }
        return re;
    }
};

// @lc code=end

