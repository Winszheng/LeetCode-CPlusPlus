class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=numbers.size()-1;
        int t;
        while(l<r){
            t = numbers[l]+numbers[r];
            if(t == target)return {l, r};
            else if(t > target)r--;
            else l++;
        }
        return {-1, -1};
    }
};